#include<stdio.h>
int get_input();
void get_array(int, int*);
void calculate_output(int,int*,int*,int,int*,int*,int,int*);
void print_output(int,int*);
int get_input()
{
	int a;
	scanf("%d",&a);
	return a;
}
void get_array(int n,int *a)
{
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void calculate_output(int n1,int *start,int *end,int n2,int *q_start,int *q_end,int k,int *result)
{
	for(int i=0;i<n2;i++)
	{
		int unit=0;
		for(int j=q_start[i];j<q_end[i];j++)
		{
			int student_count=0;
			for(int k=0;k<n1;k++)
			{
				if(j>=start[k] && j<=end[k])
					student_count++;
			}
			if(student_count>=k)
				unit++;
		}
		result[i]=unit;
	}
}
void print_output(int n,int *a)
{
	printf("Answer is =\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
}
int main()
{
	int n1,n2,n3,n4,k;
	n1=get_input();
	int start[n1];
	get_array(n1,start);
	n2=get_input();
	int end[n2];
	get_array(n2,end);
	n3=get_input();
	int q_start[n3];
	get_array(n3,q_start);
	n4=get_input();
	int q_end[n4];
	get_array(n4,q_end);
	k=get_input();
	int result[n3];
	calculate_output(n1,start,end,n3,q_start,q_end,k,result);
	print_output(n3,result);
}
