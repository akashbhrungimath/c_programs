#include<stdio.h>
int input();
void get_array(int ,int *);
void compute(int ,int *);
int count_no_of_small_nos(int,int,int *);
void my_append(int,int *,int,int);
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
	int pivot=a[0],s;
	s=count_no_of_small_nos(pivot,n,a);
	my_append(n,a,pivot,s);
}
int count_no_of_small_nos(int pivot,int n,int a[n])
{
	int s=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]<=pivot)
			s++;
	}
	return s;
}
void my_append(int n,int a[n],int pivot,int s)
{
	int j=0,k=n-1,l;
	for(int i=1;i<=s;i++)
	{
		if(a[i]<=pivot)
			a[i-1]=a[i];
		if(a[i]>pivot)
		{
			l=a[k];
			a[k--]=a[i];
			a[i-1]=l;
		}
	}
	a[s]=pivot;
}
void output(int n,int a[n])
{
	for(int i=0;i<n;i++)
		printf("%d",a[i]);
	printf("\n");
}