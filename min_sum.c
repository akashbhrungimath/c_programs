#include<stdio.h>
#include<stdlib.h>
int getInput();
int calculateSize(int);
void separateDigits(int, int, int*);
void heapsort(int , int*);
void heapify(int, int*, int);
int findMinSum(int, int*);
void printResult(int);
int main()
{
    int m, *arr, result=0, size=0;
    m = getInput();
    size = calculateSize(m);
    arr = (int *) calloc(size, sizeof(int));
    separateDigits(m, size, arr);
    heapsort(size, arr);
    result = findMinSum(size, arr);
    printResult(result);
    free(arr);
    return 0;
}
int getInput()
{
    int n;
    scanf("%d", &n);
    return n;
}
int calculateSize(int temp)
{
    int size = 0;
    while(temp != 0)
    {
        int r = temp%10;
        temp/=10;
        size++;
    }
    return size;
}
void separateDigits(int n, int size, int *a)
{
    for(int i=0; i<size; i++)
    {
        a[i] = n%10;
        n/=10;
    }
}
void heapsort(int n, int *a)
{
    for(int i=n-1; i>=0; i--)
    {
        heapify(n, a, i);
    }
}
void heapify(int size, int *a, int index)
{
    int largest = index;
    if(index<size-1 && a[index]>a[index+1])
        largest = index+1;
    if(index<size-2 && a[index]>a[index+2])
        largest = index+2;
    if(largest != index)
    {
        int temp = a[index];
        a[index] = a[largest];
        a[largest] = temp;
        heapify(size, a, largest);
    }
}
int findMinSum(int size, int *arr)
{
    int set1=0, set2=0;
    set1 = arr[0];
    for(int i=1; i<size; i++)
    {
        set2*=10;
        set2+=arr[i];
    }
    int sum = set1+set2;
    for(int i=2; i<size; i++)
    {
        set1=0;
        set2=0;
        for(int j=0; j<=i; j++)
        {
            set1*=10;
            set1+=arr[j];
        }
        for(int j=i+1; j<size; j++)
        {
            set2*=10;
            set2+=arr[j];
        }
        if(sum > set1+set2)
            sum = set1+set2;
    }
    return sum;
}
void printResult(int n)
{
    printf("The minimum sum possible by above entered no. is = %d\n", n);
}