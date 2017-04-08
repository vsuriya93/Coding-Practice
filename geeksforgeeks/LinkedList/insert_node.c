#include<stdio.h>
#include<malloc.h>

struct node
{
int num;
struct node *next;
};

typedef struct node node;

node* create_node(int n)
{
 node *temp=malloc(sizeof(node*));
 temp->num=n;
 temp->next=NULL;
 return temp;
}

void printList(node *tmp)
{
 while(tmp!=NULL)
 {
  printf("%d->",tmp->num);
  tmp=tmp->next;
 }
}

void InsertBegin(node** head,int n)
{
 node *new_node=create_node(n);
 new_node->next=*head;
 (*head)=new_node;
}

void InsertAfter(node *prev,int n)
{
 node *new_node=create_node(n);
 new_node->next=prev->next;
 prev->next=new_node;
}

void InsertEnd(node **start,int n)
{
 node *new_node=create_node(n);
 if((*start)==NULL)
 {
  (*start)=new_node;
  return ;
 }
 node *temp=(*start);
 while(temp->next!=NULL)
  temp=temp->next;
 temp->next=new_node;
 return ;
}

int main()
{
node *start=NULL;
int n;
printf("Enter Number:");
scanf("%d",&n);
InsertBegin(&start,n);
printList(start);
printf("\n");
InsertAfter(start,34);
printList(start);
printf("\n");
InsertEnd(&start,23);
printList(start);
printf("\n");
return 0;
}
