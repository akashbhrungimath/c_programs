#include<stdio.h>
int main()
{
	int n;
	n=input();
	int a[n];
	get_array(n,a);
	compute(n,a);
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
	int fn=a[0];
	
}