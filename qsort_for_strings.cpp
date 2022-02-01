#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int get_input();
void get_array(int ,char **);
int compare(const void *,const void *);
void display(int,char **);
int get_input()
{
	int n;
	scanf("%d",&n);
	return n;
}
void get_array(int n,char *a[])
{
	for(int i=0;i<n;i++)
		scanf(" %s\n",a[i]);
}
void display(int n,char *a[])
{
	printf("the sorted list is=\n");
	for(int i=0;i<n;i++)
	{
		printf("%s\n",a[i]);
	}
}
int main()
{
	int no_names,name_length,q;
	printf("enter the no. of strings you want to enter=");
	no_names=get_input();
	printf("enter the length of lenghtiest name in the list=");
	scanf("%d",&name_length);
	char *a[no_names];
	for(int i=0;i<no_names;i++)
		a[i]=(char *)malloc(name_length*sizeof(char));
	printf("enter the strings=\n");
	get_array(no_names,a);
	qsort(a,no_names,sizeof(*a),(int (*) (const void *,const void *))strcmp);
	display(no_names,a);
	return 0;
}
