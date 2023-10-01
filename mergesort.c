#include<stdio.h>
#include<stdlib.h>
void getArray(int*, int);
void mergesort(int*, int, int);
void merge(int*,int,int,int);
void printArray(int*,int);
int main()
{
    int *a,n;
    printf("enter the size of the array = ");
    scanf("%d",&n);
    a=(int*) calloc(n,sizeof(int));
    getArray(a,n);
    mergesort(a,0,n-1);
    printArray(a,n);
    free(a);
    return 0;
}
void getArray(int *arr, int size)
{
    for(int i=0; i<size; i++)
    {
        scanf("%d",&arr[i]);
    }
}
void mergesort(int *a,int start, int end)
{
    if(start >= end)
        return;
    mergesort(a,start,(start+end)/2);
    mergesort(a,(start+end)/2+1,end);
    merge(a,start,(start+end)/2,end);
}
void merge(int *a, int p, int q, int end)
{
    int i = q-p+1;
    int j = end-q;
    int *l = (int*) calloc(i,sizeof(int));
    int *r = (int*) calloc(j,sizeof(int));
    for(int m=0; m<i; m++)
    {
        l[m] = a[p+m];
    }
    for(int m=1; m<=j; m++)
    {
        r[m-1] = a[q+m];
    }
    int m=0;
    int n=0;
    for(int k=p; k<=end; k++)
    {
        if(m>=i)
        {
            for(;n<j, k<=end; n++)
            {
                a[k++] = r[n];
            }
            break;
        }
        else if(n>=j)
        {
            for(;m<i, k<=end; m++)
            {
                a[k++] = l[m];
            }
            break;
        }
        else
        {
            if(l[m]<r[n])
                a[k] = l[m++];
            else
                a[k] = r[n++];
        }
    }
}
void printArray(int *a, int size)
{
    printf("Sorted Array is =\n");
    for(int i=0; i<size; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}