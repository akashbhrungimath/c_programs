#include<stdio.h>
#include<stdlib.h>
int getn();
void getInput(int*, int);
void insertionSort(int*, int);
void printArray(int*, int);
int main()
{
    int *arr, n;
    n = getn();
    arr = (int*) calloc(n,sizeof(int));
    getInput(arr,n);
    insertionSort(arr,n);
    printArray(arr,n);
    return 0;
}
int getn()
{
    int n;
    printf("How many no.s do you want to enter = ");
    scanf("%d",&n);
    return n;
}
void getInput(int *arr, int size)
{
    for(int i=0; i<size; i++)
    {
        scanf("%d",&arr[i]);
    }
}
void insertionSort(int *arr, int size)
{
    for(int i=1; i<size; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(arr[i] < arr[j])
            {
                int temp = arr[i];
                for(int k=i; k>j; k--)
                {
                    arr[k] = arr[k-1];
                }
                arr[j] = temp;
            }
        }
    }
}
void printArray(int *arr, int size)
{
    printf("Sorted array details are = \n");
    for(int i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}