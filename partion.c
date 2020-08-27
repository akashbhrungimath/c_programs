#include<stdio.h>
int input();
void get_array(int ,int *);
void compute(int ,int *);
int count_no_of_small_nos(int,int,int *);
int count_no_of_high_nos(int,int,int *);
void collect_the_smalls(int,int,int *,int *);
void collect_the_highs(int,int,int *,int *);
void my_assemble(int,int *,int,int,int,int *,int *);
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
	int pivot=a[0],s,h;
	s=count_no_of_small_nos(pivot,n,a);
	int b[s];
	h=count_no_of_high_nos(pivot,n,a);
	int c[h];
	collect_the_smalls(n,pivot,a,b);
	collect_the_highs(n,pivot,a,c);
	my_assemble(n,a,pivot,s,h,b,c);
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
int count_no_of_high_nos(int pivot,int n,int a[n])
{
	int h=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]<pivot)
			h++;
	}
	return h;
}
void collect_the_smalls(int n,int pivot,int a[n],int b[n])
{
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]<pivot)
		{
			b[k++]=a[i];
		}
	}
}
void collect_the_highs(int n,int pivot,int a[n],int c[n])
{
	int k=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]>pivot)
		{
			c[k++]=a[i];
		}
	}
}
void my_assemble(int n,int a[n],int pivot,int s,int h,int b[s],int c[h])
{
	int j=0;
	for(int i=0;i<s;i++)
	{
		a[i]=b[i];
	}
	a[s++]=pivot;
	for(int i=s;i<n;i++)
	{
		a[i]=c[j];
		j++;
	}
}
void output(int n,int a[n])
{
	for(int i=0;i<n;i++)
		printf("%d",a[i]);
	printf("\n");
}