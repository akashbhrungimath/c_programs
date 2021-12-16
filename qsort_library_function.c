#include<stdio.h>
#include<stdlib.h>
int get_input();
void getarray(int ,int *);
int compfun(const void *,const void *);
void display(int,int *);
int get_input()
{
	int n;
	printf("enter the size of the array you want to enter=");
	scanf("%d",&n);
	return n;
}
void getarray(int n,int a[])
{
	printf("enter the arrat elements=\n");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
}
int compfun(const void *x,const void *y)
{
	return(*(int *)x-*(int *)y);
}
void display(int n,int a[])
{
	printf("the sorted array is=\n");
	for(int i=0;i<n;i++)
		printf("%d",a[i]);
	printf("\n");
}
int main()
{
	int n,*a;
	n=get_input();
	a=(int *)malloc(n*sizeof(int));
	getarray(n,a);
	qsort(a,n,sizeof(int),compfun);
	display(n,a);
	return 0;
}
