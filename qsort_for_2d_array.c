#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int get_input();
void get_array(int ,char (*)[]);
int compare(const void *,const void *);
void display(int,char (*)[]);
int get_input()
{
	int n;
	printf("enter the no. of strings you want to enter=");
	scanf("%d",&n);
	return n;
}
void get_array(int n,char a[n][100])
{
	printf("enter the strings=\n");
	for(int i=0;i<n;i++)
		scanf(" %s\n",a[i]);
}
void display(int n,char a[n][100])
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
	no_names=get_input();
	char a[no_names][100];
	get_array(no_names,a);
	qsort(a,no_names,100,(int (*) (const void *,const void *))strcmp);
	display(no_names,a);
	return 0;
}
