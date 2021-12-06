#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int get_input();
int get_ndo();
void get_digits(int,int *);
void find_combinations(int,int *,int,int *);
void constct_row(int,int *,int,int *);
//void display(int ,int *);
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
void find_combinations(int n,int a[],int size,int *combn)
{
	int x=0;
	for(int i=0;i<size;i++)
	{
		constct_row(i,x,n,a,size,combn);
	}
}
void constct_row(int i,int x,int n,int a[],int size,int *combn)
{
	*(*(combn+i)+x)=a[i];
	for(int j=0;j<n-1;j++)
	{
		if(x<n)
			constct_row(i,x+1,n,a,size,combn);
		
	}
}
/*void display(int n,int a[n])
{
	for(int i=0;i<n;i++)
    {
        printf("%d\n",a[i]);
    }
}*/
int main()
{
    int n,size=0,ndo,*a,*combn;
    n=get_input();
    ndo=get_ndo();
    size=pow(n,ndo);
	a=(int *)malloc(n*sizeof(int));
	combn=(int *)malloc((size*n)*sizeof(int));
	get_digits(n,a);
	find_combinations(n,a,size,combn);
	//display(n,a);
    return 0;
}
