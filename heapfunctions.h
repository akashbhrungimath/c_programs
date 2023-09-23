//This library includes all the heap data structure functions
#include<stdio.h>
#include<stdlib.h>

#ifndef _heapds_h_
#define _heapds_h_

//  important macros required for heap activities
#define lChild(i) 2*i+1;
#define rChild(i) 2*i+2;
#define Parent(i) (i+1)/2;

//  defining a struct type for heap which consists an array and it's size
struct heaparray{
    int *arr;
    int heapsize;
};
typedef struct heaparray HeapArray;

void myswap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
//  checks if the node violates heap property and heapify accordingly 
extern void Max_heapify(HeapArray heaparr, int i)
{
    //  #for looping approach   -   inefficient

    // for(int i=heaparr.heapsize-1; i>0; i--)
    // {
    //     if(heaparr.arr[i] > heaparr.arr[parent(i)])
    //     {
    //         swap(&heaparr.arr[i], &heaparr.arr[parent(i)]);
    //     }
    // }

    //  #recurrence approach    -   efficient
    if(i < 0)
        return;
    int l = lChild(i);
    int r = rChild(i);
    int largest = i;
    if(l < heaparr.heapsize && heaparr.arr[l] > heaparr.arr[i])
        largest = l;
    if(r < heaparr.heapsize && heaparr.arr[r] > heaparr.arr[largest])
        largest = r;
    if(largest != i)
    {
        myswap(&heaparr.arr[i], &heaparr.arr[largest]);
        Max_heapify(heaparr, largest);
    }
}
//  inserts value into the heap without violating the heap property
extern void insert(int val, HeapArray heaparr)
{
    heaparr.arr = (int*) realloc(heaparr.arr, (++heaparr.heapsize)*sizeof(int));
    heaparr.arr[heaparr.heapsize-1] = val;
    for(int i=heaparr.heapsize-1; i>0; i--)
    {
        int p = Parent(i);
        if(heaparr.arr[p] < heaparr.arr[i])
            myswap(&heaparr.arr[p], &heaparr.arr[i]);
    }
}
//  #merge merges two heaps given to it resulting in new heap with combination of both
//  the heaps
//extern int * merge(HeapArray, HeapArray);
//  returns the maximum value of the heap which is the root value
extern int getmax(HeapArray heap)
{
    return heap.arr[0];
}
//  #createHeap takes the input no.s and heapifies the input array
extern HeapArray getHeap()
{
    HeapArray heaparr;
    printf("How many no.s you want to enter = ");
    scanf("%d", &heaparr.heapsize);
    heaparr.arr = (int*) malloc(heaparr.heapsize*sizeof(int));
    printf("Enter the no.s = \n");
    for(int i=0; i<heaparr.heapsize; i++)
    {
        scanf("%d", &heaparr.arr[i]);
    }
    for(int i=((heaparr.heapsize)/2)-1; i>=0; i--)
    {
        Max_heapify(heaparr, i);
    }
    return heaparr;
}
//  checks whether the given array is a heap or not
int check(HeapArray heap, int i)
{
    int l = lChild(i);
    int r = rChild(i);
    if(i >= (heap.heapsize-1)/2)
        return 1;
    if(heap.arr[i] < heap.arr[l] || heap.arr[i] < heap.arr[r])
        return 0;
    else
        return check(heap, i++);
}
extern int checkHeapProperty(HeapArray heaparr)
{
    return check(heaparr, 0);

    //comment out above #return statement and uncomment below code to use #for loop for
    //checking if the entered array is heap or not

    // for(int i=0; i<(heaparr.heapsize-1)/2; i++)
    // {
    //     int l = lChild(i);
    //     int r = rChild(i);
    //     if(heaparr.arr[i] < heaparr.arr[l] || heaparr.arr[i] < heaparr.arr[r])
    //         return 0;
    // }
    // return 1;
}
//  deletes the heap created
extern void deleteHeap(HeapArray heaparr)
{
    free(heaparr.arr);
    heaparr.heapsize = 0;
}
//  prints the heap array
extern void printHeap(HeapArray heap)
{
    printf("Elements of the heap are as follows..\n");
    for(int i=0; i<heap.heapsize; i++)
    {
        printf("%d ",heap.arr[i]);
    }
    printf("\n");
}

#endif