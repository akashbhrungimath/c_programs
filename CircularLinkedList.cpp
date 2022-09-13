#include<iostream>
using namespace std;
struct Node
{
  int data;
  Node *next;
  bool operator ==(Node *n2)
  {
    if(this->data==n2->data)
      return true;
    return false;
  }
  bool operator !=(Node *n2)
  {
    if(this->data!=n2->data)
      return true;
    return false;
  }
};
class LinkedList
{
  struct Node *last=NULL;
public:
  LinkedList(){}
  LinkedList(int a)
  {
    last=(struct Node*)malloc(sizeof(struct Node));
    last->data=a;
    last->next=last;
  }
  void addElement(int a)
  {
    if(last==NULL)
    {
      last=(struct Node*)malloc(sizeof(struct Node));
      last->data=a;
      last->next=last;
      return;
    }
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    temp->data=a;
    temp->next=last->next;
    last->next=temp;
    last=temp;
  }
  ~LinkedList()
  {
    if(last==NULL)
    {
      return;
    }
    while(last==NULL)
    {
      struct Node *temp=last;
      last=last->next;
      delete (temp);
    }
  }
  void display()
  {
    if(last==NULL)
    {
      return;
    }
    struct Node *temp=last->next;
    while(temp!=last)
    {
      cout<<temp->data<<endl;
      temp=temp->next;
    }
    cout<<last->data<<endl;
  }
};
int main()
{
  LinkedList l1;
  l1.addElement(2);
  l1.addElement(4);
  l1.display();
  return 0;
}
