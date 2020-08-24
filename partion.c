#include<stdio.h>
int input();
void get_array(int ,int *);
void compute(int ,int *,int *);
int count_no_of_small_nos(int,int,int *);
void my_append(int,int *,int *,int,int);
void output(int ,int *);
int main()
{
	int n;
	n=input();
	int a[n],b[n];
	get_array(n,a);
	compute(n,a,b);
	output(n,b);
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
void compute(int n,int a[n],int b[n])
{
	int pivot=a[0],s;
	s=count_no_of_small_nos(pivot,n,a);
	my_append(n,a,b,pivot,s);
}
int count_no_of_small_nos(int pivot,int n,int a[n])
{
	int s=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]<pivot)
			s++;
	}
	return s;
}
void my_append(int n,int a[n],int b[n],int pivot,int s)
{
	int j=0;
	b[s++]=pivot;
	for(int i=0;i<n;i++)
	{
		if(a[i]<pivot)
			b[j++]=a[i];
		if(a[i]>pivot)
			b[s++]=a[i];
	}
}
void output(int n,int b[n])
{
	for(int i=0;i<n;i++)
		printf("%d",b[i]);
	printf("\n");
}