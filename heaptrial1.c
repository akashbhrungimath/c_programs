#include<stdio.h>
#include "heapfunctions.h"

int main()
{
    HeapArray heap;
    heap = getHeap();
    printHeap(heap);
    return 0;
}