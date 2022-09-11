#include<iostream>
using namespace std;
struct Node
{
  int data;
  Node* next;
  Node(int a)
  {
    data=a;
    next=NULL;
  }
};
class Queue
{
  Node *head,*tail;
public:
  Queue(){}
  Queue(int a)
  {
    Node* temp=new Node(a);
    head=tail=temp;
  }
  void enQueue(int a)
  {
    Node* temp=new Node(a);
    if(head==NULL)
    {
      head=tail=temp;
      return;
    }
    tail->next=temp;
    tail=temp;
  }
  ~Queue()
  {
    while(head==NULL)
    {
      Node* temp=head;
      head=head->next;
      delete (temp);
    }
  }
  void display()
  {
    if(head==NULL)
    {
      cout<<"There is nothing in the Queue to display"<<endl;
      return;
    }
    Node* temp=head;
    while(temp!=NULL)
    {
      cout<<temp->data<<endl;
      temp=temp->next;
    }
  }
  void deQueue()
  {
    if(head==NULL)
    {
      cout<<"Queue is empty"<<endl;
      return;
    }
    Node* temp=head;
    head=head->next;
    if(head==NULL)
      tail=NULL;
    delete(temp);
  }
};
int main()
{
  Queue q1(2);
  cout<<"Before adding element to the Queue"<<endl;
  q1.display();
  q1.enQueue(3);
  q1.enQueue(5);
  q1.enQueue(6);
  cout<<"After adding the element to the Queue"<<endl;
  q1.display();
  q1.deQueue();
  cout<<"After once dequeueing"<<endl;
  q1.display();
  return 0;
}
