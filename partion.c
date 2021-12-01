#include<stdio.h>
int input();
void get_array(int ,int *);
void compute(int ,int *);
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
void compute(int n,int a[])
{
	int pivot=a[0],k=n-1,i=1,l,c=0;
	while(i<k)
	{
		while(a[i]<=pivot && i<k)
			i++;	
		while(a[k]>pivot && i<k)
			k--;
		if(a[i]>pivot && a[k]<=pivot)
		{
			l=a[k];
			a[k]=a[i];
			a[i]=l;
			i++;
			k--;
		}
	}
	if(a[k]<pivot)
	{
		a[c]=a[k];
		a[k]=pivot;
	}
}
void output(int n,int a[n])
{
	for(int i=0;i<n;i++)
		printf("%d",a[i]);
	printf("\n");
}