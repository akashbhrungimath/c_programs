#include<stdio.h>
#include<stdlib.h>
int getSize();
void getArray(int, int*);
int FindNthSmallest(int, int, int*, int, int);
int Partition(int, int, int*, int, int);
void mySwap(int*, int*);
void printIndex(int, int);
int main()
{
    int size = 0, *arr, n = 1, result = 0;
    printf("Enter the size of the array = ");
    size = getSize();
    arr = (int*) calloc(size, sizeof(int));
    printf("Enter the array elements = \n");
    getArray(size, arr);
    printf("Enter the value of n = ");
    n = getSize();
    result = FindNthSmallest(n, size, arr, 0, size);
    printIndex(result, n);
    free(arr);
}
int getSize()
{
    int n;
    scanf("%d",&n);
    return n;
}
void getArray(int n, int *a)
{
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
}
int FindNthSmallest(int n, int size, int *a, int start, int end)
{
    int index = -1;
    index = Partition(n, size, a, start, end);
    if(index+1 > n)
        index = FindNthSmallest(n, size, a, start, index);
    else if(index+1 < n)
        index = FindNthSmallest(n, size, a, index+1, end);
    else if(index+1 == n)
        return a[index];
    return index;
}
int Partition(int n, int size, int *arr, int start, int end)
{
    if(start >= end)
        return start;
    int pivot = arr[start];
    int l = start;
    while(arr[l] <= pivot)
        l++;
    int r = end-1;
    while(arr[r] > pivot)
        r--;
    while(l < r)
    {
        mySwap(&arr[l], &arr[r]);
        l++;
        r--;
        while(arr[l] <= pivot)
            l++;
        while(arr[r] > pivot)
            r--;
    }
    int temp = arr[r];
    arr[r] = pivot;
    arr[start] = temp;
    return r;
}
void mySwap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printIndex(int i, int n)
{
    if(n == 1)
        printf("The index with the %dst smallest value is = %d\n", n, i);
    else if(n == 2)
        printf("The index with the %dnd smallest value is = %d\n", n, i);
    else
        printf("The index with the %dth smallest value is = %d\n", n, i);
}
