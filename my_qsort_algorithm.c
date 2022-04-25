#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int get_input();
void get_array(int ,char **);
void my_qsort(char**,int,int,int (*my_strcmp)(const void ** ,const void **));
int mystrcmp(const void **,const void **);
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
void my_qsort(char **a,int no_names,int size_of_name,int (*my_strcmp)(const void **,const void **))
{
	int flag;
	char *temp;
	temp=(char*)malloc(size_of_name*sizeof(char));
	for(int i=0;i<no_names;i++)
	{
		for(int j=i+1;j<no_names;j++)
		{
			flag=my_strcmp((void*)&a[i],(void*)&a[j]);
			if(flag>0)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
int mystrcmp(const void **a,const void **b)
{
	char** p=(char**) a;
	char** q=(char**) b;
	return strcmp(*p,*q);
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
	my_qsort(a,no_names,sizeof(*a),&mystrcmp);
	display(no_names,a);
	return 0;
}
