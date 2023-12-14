#include<stdio.h>
#include<stdlib.h>
int getNum();
void getArray(int*, int);
void CalculateComptime(int*, int*, int*, int);
void LoadBalancer(int*, int*, int, int, int*, int*);
void ArrangeProcesses(int*, int*, int);
void heapifyProcresses(int*, int*, int, int);
void AlloteProcesses(int, int*, int*, int*, int, int*, int, int, int*);
void DisplayResult(int*, int);
int main()
{
    int n,m, *arrival, *bursttime, *comptime, *allotedServers, *temparrival;
    printf("Enter the no. of servers available = ");
    n = getNum();
    printf("How many requests to be processed = ");
    m = getNum();
    arrival = (int *) calloc(m, sizeof(int));
    temparrival = (int *) calloc(m, sizeof(int));
    bursttime = (int *) calloc(m, sizeof(int));
    comptime = (int *) calloc(m, sizeof(int));
    allotedServers = (int *) calloc(m, sizeof(int));
    printf("Enter the arrival times of the processes : \n");
    getArray(arrival, m);
    for(int i=0; i<m; i++)
    {
        temparrival[i] = arrival[i];
    }
    printf("Enter the burst times of the processes : \n");
    getArray(bursttime, m);
    CalculateComptime(arrival, bursttime, comptime, m);
    LoadBalancer(arrival, comptime, m, n, allotedServers, temparrival);
    DisplayResult(allotedServers, m);
    // for(int i=0; i<m; i++)
    // {
    //     printf("%d\t %d\n",arrival[i],comptime[i]);
    // }
    free(arrival);
    free(bursttime);
    free(comptime);
    free(allotedServers);
    free(temparrival);
    return 0;
}
int getNum()
{
    int n;
    scanf("%d", &n);
    return n;
}
void getArray(int* a, int n)
{
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
}
void CalculateComptime(int *at, int *bt, int *ct, int m)
{
    for(int i=0; i<m; i++)
    {
        ct[i] = at[i] + bt[i];
    }
}
void LoadBalancer(int *at, int* ct, int size, int servers, int *allotedServers, int *tar)
{
    ArrangeProcesses(at, ct, size);
    int *tempap = (int *) calloc(size, sizeof(int));
    for(int i=1; i<=servers; i++)
    {
        AlloteProcesses(size, at, ct, allotedServers, i, tar, 0, -1, tempap);
    }
    free(tempap);
}
void ArrangeProcesses(int *at, int *ct, int n)
{
    for(int i=0; i<n; i++)
    {
        heapifyProcresses(at, ct, i, n);
    }
}
void heapifyProcresses(int *at, int *ct, int index, int size)
{
    int smallest = index;
    if(index<size-1 && at[index+1]<at[index])
    {
        smallest = index+1;
    }
    else if(index<size-2 && at[index+2]<at[index])
    {
        smallest = index+2;
    }
    if(smallest != index)
    {
        int temp = at[smallest];
        at[smallest] = at[index];
        at[index] = temp;
        temp = ct[smallest];
        ct[smallest] = ct[index];
        ct[index] = temp;
        heapifyProcresses(at, ct, smallest, size);
    }
}
void AlloteProcesses(int processes, int *arrival, int *comptime, int* ap, int server, int *t, int index, int prev, int *tempap)
{
    if(index>=processes)
        return;
    if(prev == -1 && tempap[index]==0)
    {
        for(int i=0; i<processes; i++)
        {
            if(arrival[index] == t[i])
                ap[i] = server;
        }
        prev = index;
        tempap[index] = 1;
    }
    else if(tempap[index]==0 && arrival[index]>=comptime[prev])
    {
        for(int i=0; i<processes; i++)
        {
            if(arrival[index] == t[i])
                ap[i] = server;
        }
        prev = index;
        tempap[index] = 1;
    }
    AlloteProcesses(processes, arrival, comptime, ap, server, t, index+1, prev, tempap);
}
void DisplayResult(int *arr, int size)
{
    printf("The servers are being alloter for the processes as follows:\n");
    for(int i=0; i<size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
