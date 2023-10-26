#include<stdio.h>
#include<stdlib.h>
int getSize();
void getArray(int*, int);
void countingSort(int*, int);
int FindBig(int*, int);
void PrintArray(int*, int);
int main()
{
    int *arr, size;
    size = getSize();
    arr = (int*) calloc(size, sizeof(int));
    getArray(arr, size);
    countingSort(arr, size);
    PrintArray(arr,size);
    free(arr);
}
int getSize()
{
    int n;
    printf("How many enteries you want to make = ");
    scanf("%d",&n);
    return n;
}
void getArray(int *a, int n)
{
    printf("Enter the no.s\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
}
void countingSort(int *arr, int size)
{
    int *sortedArr = (int*) calloc(size, sizeof(int));
    int greater = FindBig(arr,size)+1;
    int *temp = (int*) calloc(greater, sizeof(int));
    for(int i=0; i<size; i++)
    {
        temp[arr[i]] +=1;
    }
    for(int i=1; i<greater; i++)
    {
        temp[i] += temp[i-1];
    }
    for(int i=0; i<size; i++)
    {
        sortedArr[temp[arr[i]]-1] = arr[i];
        temp[arr[i]]--;
    }
    for(int i=0; i<size; i++)
    {
        arr[i] = sortedArr[i];
    }
    free(temp);
    free(sortedArr);
}
int FindBig(int *a, int n)
{
    int result = a[0];
    for(int i=1; i<n; i++)
    {
        if(result<a[i])
            result = a[i];
    }
    return result;
}
void PrintArray(int *a, int n)
{
    printf("Array after sorting looks this way = \n");
    for(int i=0; i<n; i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}