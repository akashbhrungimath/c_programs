//This code is for max priority queue (or) Descending order priority queue.
#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node* next;
    node(int x)
    {
        data=x;
        next=NULL;
    }
};
typedef struct node Node;
class Priority_Queue
{
    Node* head=NULL;
public:
    Priority_Queue(int x)
    {
        head=new Node(x);
    }
    void push(int a)
    {
        Node* new_node=new node(a);
        if(head==NULL)
        {
            head=new_node;
            return;
        }
        Node* temp=head;
        if(temp->next==NULL)
        {
            int var=temp->data;
            temp->data=a;
            a=var;
        }
        while(temp->next!=NULL)
        {
            if(temp->data<a)
            {
                int var=temp->data;
                temp->data=a;
                a=var;
            }
            temp=temp->next;
        }
        new_node->data=a;
        temp->next=new_node;
    }
    int pop()
    {
        int x=head->data;
        Node* temp=head;
        head=head->next;
        delete(temp);
        return x;
    }
    void display_queue()
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
    void delete_queue()
    {
        while(head!=NULL)
        {
            Node* temp=head;
            head=head->next;
            delete(temp);
        }
    }
};
int main()
{
    Priority_Queue p1(2);
    p1.push(3);
    p1.push(5);
    p1.push(6);
    //p1.push(4);
    p1.display_queue();
    cout<<p1.pop()<<endl;
    p1.display_queue();
    p1.delete_queue();
    return 0;
}
