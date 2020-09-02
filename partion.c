#include<stdio.h>
int input();
void get_array(int ,int *);
void compute(int ,int *);
void my_append(int,int *,int);
void output(int ,int *);
int main()
{
	int n;
	n=input();
	int a[n];
	get_array(n,a);
	compute(n,a);
	output(n,a);
}
int input()
{
	int n;
	printf("how many numbers you want to enter=");
	scanf("%d",&n);
	return n;
}
void get_array(int n,int a[n])
{
	printf("enter the numbers =\n");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void compute(int n,int a[n])
{
	int pivot=a[0];
	my_append(n,a,pivot);
}
void my_append(int n,int a[n],int pivot)
{
	int j=0,k=n-1,l,m,o;
	for(int i=1;i<=k;i++)
	{
		if(a[i]<=pivot)
			a[i-1]=a[i];
		else
		{
			l=a[k];
			a[k--]=a[i];
			if(l>pivot)
			{
				do
				{
					o=l;
					l=a[k];
					a[k--]=o;
					if(k<i)
						break;
				}while(l>pivot);
			}
			a[i-1]=l;
		}
	}
	a[k]=pivot;
}
void output(int n,int a[n])
{
	for(int i=0;i<n;i++)
		printf("%d",a[i]);
	printf("\n");
}