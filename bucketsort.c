#include<stdio.h>
#include<stdlib.h>
int getn();
void getArray(int*, int);
void bucketSort(int*, int);
int scaling(int*, int, int, float*);
void descaling(int*, int, int, float*);
void printArray(int*, int);
int findFactor(int*, int);
struct node
{
    float value;
    struct node *next;
};
typedef struct node Node;
int main()
{
    int *arr, n;
    n = getn();
    arr = (int*) calloc(n, sizeof(int));
    getArray(arr,n);
    bucketSort(arr,n);
    printArray(arr,n);
    free(arr);
    return 0;
}
int getn()
{
    int n;
    printf("enter the no. of enteries you want to make = ");
    scanf("%d",&n);
    return n;
}
void getArray(int *arr, int size)
{
    printf("Enter the no.s \n");
    for(int i=0; i<size; i++)
    {
        scanf("%d",&arr[i]);
    }
}
void bucketSort(int *arr, int size)
{
    int factor = 1;
    Node *temparr[size];
    for(int i=0; i<size; i++)
    {
        temparr[i] = NULL;
    }
    float *f_arr = (float*) calloc(size,sizeof(float));
    factor = findFactor(arr,size);
    scaling(arr,size,factor,f_arr);
    for(int i=0; i<size; i++)
    {
        if(temparr[(int)(size*f_arr[i])] == NULL)
        {
            temparr[(int)(size*f_arr[i])] = (Node*) calloc(size, sizeof(Node));
            temparr[(int)(size*f_arr[i])]->value = f_arr[i];
            temparr[(int)(size*f_arr[i])]->next = NULL;
        }
        else
        {
            Node *current = temparr[(int)(size*f_arr[i])];
            while(current->next != NULL)
            {
                if(current->value < f_arr[i])
                {
                    int temp = f_arr[i];
                    f_arr[i] = current->value;
                    current->value = temp;
                }
                current = current->next;
            }
            if(current->value > f_arr[i])
            {
                float temp = f_arr[i];
                f_arr[i] = current->value;
                current->value = temp;
            }
            current->next = (Node*) calloc(1,sizeof(Node));
            current = current->next;
            current->value = f_arr[i];
            current->next = NULL;
        }
    }
    int index = 0;
    for(int i=0; i<size; i++)
    {
        Node *temp = temparr[i];
        while(temp != NULL)
        {
            f_arr[index++] = temp->value;
            temp = temp->next;
        }
    }
    descaling(arr,size,factor,f_arr);
}
int findFactor(int* arr, int n)
{
    int factor = arr[0];
    for(int i=1; i<n; i++)
    {
        if(factor<arr[i])
            factor = arr[i];
    }
    return factor+1;
}
int scaling(int *arr, int size, int factor, float *f_arr)
{
    for(int i=0; i<size; i++)
    {
        f_arr[i] = (float) arr[i]/factor;
    }
}
void descaling(int *arr, int n, int f, float *fa)
{
    for(int i=0; i<n; i++)
    {
        arr[i] = fa[i]*f;
    }
}
void printArray(int *arr, int size)
{
    printf("Sorted array is = \n");
    for(int i=0; i<size; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}