#include<stdio.h>
#include<stdlib.h>
int GetInput();
void GetArray(int*, int);
int FindMaxSubArray(int*, int, int, int*, int*);
int FindCrossMax(int*, int, int, int*, int*);
void PrintResult(int, int, int);
int main()
{
    int *arr, size, max_left, max_right;
    size = GetInput();
    arr = (int *) calloc(size, sizeof(int));
    GetArray(arr,size);
    int maxResult = FindMaxSubArray(arr,0,size,&max_left,&max_right);
    PrintResult(maxResult, max_left, max_right);
    free(arr);
    return 0;
}
int GetInput()
{
    int n=0;
    printf("Enter the size of the array = ");
    scanf("%d",&n);
    return n;
}
void GetArray(int *a, int n)
{
    printf("Enter the elements of the array:\n");
    for(int i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
}
int FindMaxSubArray(int *arr, int start, int end, int *ml, int *mr)
{
    if(start>=end)
        return arr[start];
    int maxSumL = FindMaxSubArray(arr, start, (start+end)/2, ml, mr);
    int maxSumR = FindMaxSubArray(arr, (start+end)/2+1, end, ml, mr);
    int maxCrossSum = FindCrossMax(arr, start, end, ml, mr);
    if(maxSumL > maxSumR && maxSumL > maxCrossSum)
        return maxSumL;
    else if(maxSumR > maxCrossSum)
        return maxSumR;
    else
        return maxCrossSum;
}
int FindCrossMax(int *arr, int start, int end, int *ml, int *mr)
{
    *ml = end/2;
    int max = 0, maxSumL = arr[end/2], maxSumR = arr[end/2+1];
    for(int i=end/2; i>=0; i--)
    {
        max += arr[i];
        if(max > maxSumL)
        {
            *ml = i;
            maxSumL = max;
        }
    }
    max = 0;
    *mr = end/2+1;
    for(int i=end/2+1; i<end; i++)
    {
        max += arr[i];
        if(max > maxSumR)
        {
            *mr = i;
            maxSumR = max;
        }
    }
    return maxSumL+maxSumR;
}
void PrintResult(int result, int maxleft, int maxright)
{
    printf("The max sub-Array in the above entered Array is :\n");
    printf("maximum left index = %d\n",maxleft);
    printf("maximum right index = %d\n",maxright);
    printf("with the maximum sum of = %d\n",result);
}