#include<stdio.h>
#include<stdlib.h>
int input();
int ** FindAllTheSequences(int, int, int*, int**);
void printSequence(int, int, int**);

int main()
{
	int a, b, **arr, size = 1;
	a = input();
	b = input();
    arr = (int**) malloc(sizeof(int));
	*(arr+0) = (int*) malloc(b*sizeof(int));
	arr = FindAllTheSequences(a, b, &size, arr);
	printf("%d\n",size);
	printSequence(size, b, arr);
	for(int i=0; i<a; i++)
	{
		free(arr[i]);
	}
	return 0;
}
int input()
{
	int n;
	printf("Enter the no = ");
	scanf("%d", &n);
	return n;
}
int ** FindAllTheSequences(int a, int b, int *size, int** arr)
{
	int x = a, sum=0, y=0, i=1;
    arr[0][0] = a;
    while(arr[i-1][b-1] == 0 || x > a/2)
	{
        (*size)++;
        arr = realloc(arr, (*size)*sizeof(int**));
        *(arr+(*size-1)) = (int*) malloc(b*sizeof(int));
		if(arr == NULL)
		{
			printf("Memory cannot be allocated to the array..");
			return 0;
		}
        x = arr[i-1][0]-1;
		sum = 0;
		for(int j=0; j<b; j++)
		{
			arr[i][j] = x;
			sum += arr[i][j];
			if(a-sum < x)
				x = a-sum;
			if(sum >= a)
			{
				if(j < b-1 && arr[i][j] > 1 && j != 0)
				{
					x = arr[i][j];
					x--;
					i++;
                    (*size)++;
                    arr = realloc(arr, *(size)*sizeof(int**));
                    *(arr+(*size-1)) = (int*) malloc(b*sizeof(int));
					if(arr == NULL)
					{
						printf("Memory cannot be allocated to the array..");
						return 0;
					}
					for(int k=0; k<j; k++)
                    {
						arr[i][k] = arr[i-1][k];
					}
                    arr[i][j] = x;
					sum = 0;
					for(int k=0; k<=j; k++)
						sum += arr[i][k];
					x = a-sum;
					continue;
				}
				else
					break;
			}
		}
        i++;
        x = arr[i-1][0];
	}
    return arr;
}
void printSequence(int a, int b, int **arr)
{
	for(int i=0; i<a; i++)
	{
		for(int j=0; j<b; j++)
		{
			printf("%d ", *(*(arr+i)+j));
		}
		printf("\n");
	}
}