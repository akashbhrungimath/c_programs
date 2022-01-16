#include<iostream>
using namespace std;
class partition
{
	int n,*a;
	public:
	void input();
	void get_array();
	friend void compute(partition);
	void output();
};
void partition::input()
{
	cout<<"how many numbers you want to enter=";
	cin>>n;
}
void partition::get_array()
{
	a=(int*)calloc(n,sizeof(int));
	cout<<"enter the numbers =\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
}
void compute(partition p)
{
	int pivot=p.a[0],k=p.n-1,i=0,l,c=0;
	while(p.a[i]<=pivot)
		i++;	
	while(p.a[k]>pivot)
		k--;
	while(i<k)
	{
		l=p.a[k];
		p.a[k]=p.a[i];
		p.a[i]=l;
		i++;
		k--;
		while(p.a[i]<=pivot)
			i++;	
		while(p.a[k]>pivot)
			k--;
	}
	if(p.a[k]<pivot)
	{
		p.a[c]=p.a[k];
		p.a[k]=pivot;
	}
}
void partition::output()
{
	for(int i=0;i<n;i++)
		cout<<a[i];
	cout<<"\n";
}
int main()
{
	partition p;
	p.input();
	p.get_array();
	compute(p);
	p.output();
	return 0;
}
