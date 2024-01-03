#include<stdio.h>
#include<stdlib.h>
int getInput();
void getArray(int, int*);
void getArray(int, int*);
void Display(int, int*);
int main()
{
    int n, *arr;
    n = getInput();
    arr = (int *) calloc(n, sizeof(int));
    getArray(n, arr);
    Display(n, arr);
    return 0;
}
int getInput()
{
    int n;
    scanf("%d",&n);
    return n;
}
void getArray(int size, int *arr)
{
    printf("Enter the array elements :\n");
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void Display(int n, int *a)
{
    printf("Elements in the array are: \n");
    for(int i=0; i<n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
}