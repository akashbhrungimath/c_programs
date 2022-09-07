#include<iostream>
using namespace std;
struct Node
{
	int key;
	Node* next=NULL;
};
class LinkedList
{
	Node* head=NULL;
	int curr_len=0;
	public:
	LinkedList(){}
	~LinkedList()
	{
		for(int i=0;i<curr_len;i++)
		{
			Node* temp=head;
			head=head->next;
			delete temp;
		}
	}
	void push(int value)
	{
		if(head==NULL)
		{
			head=new Node();
			head->key=value;
		}
		else
		{
			Node* t=head;
			while(t->next!=NULL)
				t=t->next;
			t->next=new Node();
			t->next->key=value;
		}
		curr_len++;
	}
	int operator[](int index)
	{
		if(index>curr_len)
		{
			cout<<"Index error: No specifies index is present"<<endl;
			return 0;
		}
		Node* t=head;
		for(int i=0;i<index;i++)
			t=t->next;
		return t->key;
	}
	void display()
	{
		Node* t=head;
		while(t!=NULL)
		{
			cout<<t->key<<endl;
			t=t->next;
		}
	}
};
int main()
{
	LinkedList l1;
	l1.push(2);
	l1.push(3);
	l1.push(5);
	cout<<l1[0]<<endl;
	//cout<<l1[1]<<endl;
	l1.display();
	return 0;
}
