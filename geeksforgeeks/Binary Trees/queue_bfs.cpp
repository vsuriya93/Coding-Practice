#include<iostream>
using namespace std;

struct node
{
 int data;
 struct node *left,*right;
};

struct queue
{
 struct node *data;
 struct queue *next;
};

typedef struct node node;
typedef struct queue queue;

node *createNode(int num)
{
 node *element=new node;
 element->data=num;
 element->left=NULL;
 element->right=NULL;
 return element;
}

queue *createQueueElement(node *nodeElement)
{
 queue *element=new queue;
 element->data=nodeElement;
 element->next=NULL;
 return element;
}

void inorder(node *root)
{
 if(root==NULL)
  return;
 else
 {
  inorder(root->left);
  cout<<root->data<<"->";
  inorder(root->right);
 }
}

void printQueue(queue *head)
{
 while(head)
  {
   cout<<head->data<<"->";
   head=head->next;
  }
  return ;
}

void enQueue(queue **head,node *nodeElement)
{
 if(*head==NULL)
 {
  (*head)=createQueueElement(nodeElement);
  return;
 }
 queue *runner=*head;
 while(runner->next!=NULL)
 {
  runner=runner->next;
 }
 runner->next=createQueueElement(nodeElement);
 return ;
}

node * deQueue(queue **head)
{
 if(*head==NULL)
 {
  return NULL;
 }
 queue *element=*head;
 node *val=(*head)->data;
 (*head)=(*head)->next;
 delete (element);
 return val;
}

queue *head=NULL;

void printLevel(node *root)
{
 if(root==NULL)
  return;
 node *temp=root;
 while(temp)
 {
  cout<<temp->data<<"->";
  if(temp->left)
   enQueue(&head,temp->left);
  if(temp->right)
   enQueue(&head,temp->right);
  temp=deQueue(&head);
 }
 cout<<"\n";
}

int main()
{
 node *root=createNode(1);
 root->left=createNode(2);
 root->right=createNode(3);
 root->left->left=createNode(4);
 root->left->right=createNode(5);
 root->right->left=createNode(6);
 root->right->right=createNode(7);
 root->right->left->left=createNode(8);
 root->left->right->left=createNode(9);
 inorder(root);
 cout<<"\n";
 printLevel(root);
 return 0;
}
