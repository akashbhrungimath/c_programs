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
	return 0;
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
	int k=n-1,i=1,b,l,o;
	while(i<=k)
	{
		if(a[i]<=pivot)
		{
			if(a[i+1]>pivot)
			{
				a[i-1]=a[i];
				i++;
			}
			else
			{
				b=i-1;
				do
				{
					if(a[i+1]>pivot)
						a[b]=a[i];
					i++;
				}while(a[i]<=pivot);
			}
		}
		else
		{
			l=a[k];
			if(l<=pivot)
				a[k--]=a[i];
			else 
				l=a[i];
			if(l>pivot)
			{
				do
				{
					o=l;
					l=a[k];
					if(l<pivot)
						a[k--]=o;
					else
						l=a[k--];
				}while(k+1>i);
			}
			a[i-1]=l;
			i++;
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