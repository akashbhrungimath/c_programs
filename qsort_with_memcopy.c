#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int get_input();
void get_array(int ,char **);
void bubblesort(void**,int,int,int (*fun)(const void ** ,const void **));
int my_fun(const void **,const void **);
void display(int,char **);
int get_input()
{
	int n;
	scanf("%d",&n);
	return n;
}
void get_array(int n,char **a)
{
	for(int i=0;i<n;i++)
		scanf(" %s\n",*(a+i));
}
void bubblesort(void **a,int no_names,int size_of_name,int (*fun)(const void **,const void **))
{
	int flag;
	void *temp;
	temp=(void*)malloc(size_of_name);
	for(int i=0;i<no_names-1;i++)
	{
		for(int j=i+1;j<no_names;j++)
		{
			flag=fun((const void**)a+i,(const void**)a+j);
			if(flag>0)
			{
				memcpy(temp,(const void*)a+(i*size_of_name),size_of_name);
				memcpy((void*)a+(i*size_of_name),(const void*)a+(j*size_of_name),size_of_name);
				memcpy((void*)a+(j*size_of_name),(const void*)temp,size_of_name);
			}	
		}
	}
	free(temp);
}
int my_fun(const void **a,const void **b)
{
	return strcmp(*(char**)a,*(char**)b);
}
void display(int n,char **a)
{
	printf("the sorted list is=\n");
	for(int i=0;i<n;i++)
		printf("%s\n",*(a+i));
}
int main()
{
	int no_names,name_length,q;
	printf("enter the no. of strings you want to enter=");
	no_names=get_input();
	printf("enter the length of lenghtiest name in the list=");
	name_length=get_input();
	name_length++;
	char *a[no_names];
	for(int i=0;i<no_names;i++)
		a[i]=(char *)malloc(name_length*sizeof(char));
	printf("enter the strings=\n");
	get_array(no_names,a);
	bubblesort((void**)a,no_names,sizeof(*a),&my_fun);
	display(no_names,a);
	for(int i=0;i<no_names;i++)
		free(a[i]);
	return 0;
}
