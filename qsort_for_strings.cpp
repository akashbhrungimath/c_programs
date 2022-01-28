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
	printf("enter the no. of strings you want to enter=");
	scanf("%d",&n);
	return n;
}
void get_array(int n,char *a[])
{
	printf("enter the strings=\n");
	for(int i=0;i<n;i++)
		scanf(" %s\n",a[i]);
}
int compare(const void *x,const void *y)
{
	int n;
	n=strcmp((char*)x,(char*)y);
	printf("strcmp value is=%d\n",n);
	printf("%p %s \n%p %s \n",x,(char*)x,y,(char*)y);
	if(n<0)
		return -1;
	else if(n>0)
		return 1;
	else
		return 0;
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
	no_names=get_input();
	printf("enter the length of lenghtiest name in the list=");
	scanf("%d",&name_length);
	char *a[no_names];
	for(int i=0;i<no_names;i++)
		a[i]=(char *)malloc(name_length*sizeof(char));
	get_array(no_names,a);
	printf("%p %s \n%p %s\n%p %s \n",a[0],a[0],a[1],a[1],a[2],a[2]);
	qsort(a,no_names,sizeof(*a),compare);
	display(no_names,a);
	return 0;
}
