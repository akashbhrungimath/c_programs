#include<iostream>
using namespace std;
struct Node
{
  int data;
  Node* left;
  Node* right;
  Node(int a)
  {
    data=a;
    left=NULL;
    right=NULL;
  }
};
class BinaryTree
{
  Node* root;
  void print(Node* temp)
  {
    if(temp==NULL)
      return;
    cout<<temp->data<<endl;
    print(temp->left);
    print(temp->right);
  }
public:
  BinaryTree(){}
  BinaryTree(int a)
  {
    root=new Node(a);
  }
  void addElement(int a)
  {
    if(root==NULL)
    {
      root=new Node(a);
    }
    Node* n=root;
    while(1)
    {
      if(a<n->data)
        if(n->left)
          n=n->left;
        else
        {
          n->left=new Node(a);
          return;
        }
      else if(a>n->data)
        if(n->right)
          n=n->right;
        else
        {
          n->right=new Node(a);
          return;
        }
      else
        return;
    }
  }
  void display()
  {
    print(root);
  }
};
int main()
{
  BinaryTree b1(2);
  b1.addElement(5);
  b1.display();
  return 0;
}
