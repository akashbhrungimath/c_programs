#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int get_input();
int get_ndo();
void get_digits(int,int *);
void find_combinations(int,int *,int,int **,int);
//void xyz(int,int,int,int *,int,int **,int);
void display(int,int,int **);
int get_input()
{
	int a;
	printf("enter the no.=");
	scanf("%d",&a);
	return a;
}
int get_ndo()
{
	int n;
	printf("enter the size of output you want=");
	scanf("%d",&n);
	return n;
}
void get_digits(int n,int a[])
{
	printf("enter the digits of which you need the combinations=");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
}
void find_combinations(int n,int a[],int size,int **combn,int ndo)
{
	int q=1,r=0,s;
	for(int i=ndo-1;i>=0;i--)
	{
		s=0;
		int x=pow(n,q);
		for(int j=0;j<(size/x);j++)
		{
			int y=pow(n,r);
			for(int l=0;l<n;l++)
			{
				for(int k=0;k<y;k++)
				{
					combn[s++][i]=a[l];
				}
			}
		}
		r++;
		q++;
	}
}
void display(int size,int ndo,int **a)
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<ndo;j++)
			printf("%d\t",*(*(a+i)+j));
		printf("\n");
	}
}
int main()
{
	int n,size=0,ndo,*a;
	int **combn;
	n=get_input();
	ndo=get_ndo();
	size=pow(n,ndo);
	a=(int *)malloc(n*sizeof(int));
	combn=(int **)malloc((size*n)*sizeof(int));
	for(int i=0;i<size;i++)
		combn[i]=(int *)malloc(ndo*sizeof(int));
	get_digits(n,a);
	find_combinations(n,a,size,combn,ndo);
	display(size,ndo,combn);
	return 0;
}
