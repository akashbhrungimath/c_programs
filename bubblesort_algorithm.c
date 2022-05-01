#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int get_input();
void get_array(int ,char **);
void bubblesort(void**,int,int,int (*my_strcmp)(const void ** ,const void **));
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
	{
		scanf(" %s\n",a[i]);
	}
}
void bubblesort(void **a,int no_names,int size_of_name,int (*my_strcmp)(const void **,const void **))
{
	int flag;
	void **temp1,**temp2,**temp3;
	temp1=(void**)malloc(1);
	*temp1=(void*)malloc(size_of_name);
	temp2=(void**)malloc(1);
	*temp2=(void*)malloc(size_of_name);
	temp3=(void**)malloc(1);
	*temp3=(void*)malloc(size_of_name);
	for(int i=0;i<no_names-1;i++)
	{
		temp2=a+i;
		for(int j=i+1;j<no_names;j++)
		{
			temp3=a+j;
			flag=my_strcmp((const void**)a+i,(const void**)a+j);
			if(flag>0)
			{
				*temp1=*temp2;
				*temp2=*temp3;
				*temp3=*temp1;
			}
			
		}
	}
}
int mystrcmp(const void **a,const void **b)
{
	return strcmp(*(char**)a,*(char**)b);
}
void display(int n,char **a)
{
	printf("the sorted list is=\n");
	for(int i=0;i<n;i++)
	{
		printf("%s\n",*(a+i));
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
	bubblesort((void**)a,no_names,sizeof(*a),&mystrcmp);
	display(no_names,a);
	return 0;
}
