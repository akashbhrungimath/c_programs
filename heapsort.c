#include<stdio.h>
#include "heapfunctions.h"
void heapSort(HeapArray);
void heapify(int*, int, int);
int main()
{
    HeapArray a;
    a = getHeap();
    heapSort(a);
    printHeap(a);
    deleteHeap(a);
}
void heapSort(HeapArray h)
{
    for(int i=h.heapsize-1; i>=0; i--)
    {
        heapify(h.arr, h.heapsize, i);
    }
}
void heapify(int *a, int size, int i)
{
    int largest=i;
    if(i<size-1 && a[i+1]<a[i])
        largest = i+1;
    if(i<size-2 && a[i+2]<a[largest])
        largest = i+2;
    if(largest!=i)
    {
        int temp = a[largest];
        a[largest] = a[i];
        a[i] = temp;
        heapify(a, size, largest);
    }
}