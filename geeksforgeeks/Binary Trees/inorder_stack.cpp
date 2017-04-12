#include<iostream>
using namespace std;

struct node
{
 int data;
 struct node *left,*right;
};

struct stack
{
 struct node *data;
 struct stack *next;
};

typedef struct node node;

stack *stack_head=NULL;

node *createNode(int num)
{
 node *element=new node;
 element->data=num;
 element->left=NULL;
 element->right=NULL;
 return element;
}

void inorder(node *root)
{
 if(root==NULL)
  return ;
 inorder(root->left);
 cout<<root->data<<"->";
 inorder(root->right);
}

stack * createStackNode(node *e)
{
 stack *element=new stack;
 element->data=e;
 element->next=NULL;
 return element;
}

void push(node *element)
{
 if(stack_head==NULL)
  stack_head=createStackNode(element);
 else{
  stack *e=createStackNode(element);
  e->next=stack_head;
  stack_head=e;
 }
 return;
}

bool isEmpty(stack *s)
{
 if(s==NULL)
  return 1;
 else
  return 0;
}

node * pop()
{
 if(stack_head==NULL)
  return NULL;
 else
 {
  stack *e=stack_head;;
  node *val=e->data;
  stack_head=stack_head->next;
  delete (e);
  return val;
 }
}


void printStack(stack *head)
{
 stack *val=head;
 if(val==NULL)
 {
  cout<<"Empty Stack";
 }
 while(val)
 {
  cout<<val->data<<"->";
  val=val->next;
 }
}

void inorderIterative(node *root)
{
 if(root==NULL)
  return;
 node *curr=root;
 int exit=0;
 while(!exit)
 {
  if(curr!=NULL)
  {
     push(curr);
  //   printStack(stack_head);
     curr=curr->left;
  }
  else
  {
   if(!isEmpty(stack_head))
   {
    curr=pop();
    cout<<curr->data<<"->";
    curr=curr->right;
   }
   else
     exit=1;
  }
 }
}


int main()
{
 node *root=createNode(1);
 root->left=createNode(2);
 root->right=createNode(3);
 root->left->left=createNode(4);
 root->left->right=createNode(5);
 inorder(root);
 cout<<"\n";
 inorderIterative(root);
}
