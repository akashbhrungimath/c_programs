#include<stdio.h>
int input();
void get_array(int ,int *);
void compute(int ,int *,int *);
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
	int p=a[0];
	b[n]=(0),b[0]=a[0];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(p<a[j])
			{
				for(int k=j;k>=0;k--)
					b[k]=b[k-1];
				b[0]=a[i];
			}
			if(p>a[j])
			{
				for(int k=n-1;k>i;k--)
					b[k]=b[k-1];
				b[i]=a[i];
			}
		}
	}
}
void output(int n,int b[n])
{
	for(int i=0;i<n;i++)
		printf("%d",b[i]);
	printf("\n");
}