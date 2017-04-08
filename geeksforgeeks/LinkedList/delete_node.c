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
 if(tmp==NULL)
 {
  printf("\nList Empty");
 }
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

void DeleteNode(node **head, int n)
{
 if(*head==NULL)
 {
  printf("\nEmpty List!!");
  return ;
 }
 node *temp=*head,*prev;
 if((*head)!=NULL && (*head)->num==n)
 {
  (*head)=(*head)->next;
  free(temp);
  return;
 }
 while(temp!=NULL && temp->num!=n)
 {
  prev=temp;
  temp=temp->next;
 }
 if(temp==NULL)
 {
  printf("\nElement Not Present\n");
  return ;
 }
 prev->next=temp->next;
 free(temp);
 return ;
}

void DeletePosition(node **head,int pos)
{
 if(pos<0)
 {
  printf("\nInvalid Position\n");
  return ;
 }
 if(*head==NULL)
 {
  printf("\nEmpty List");
  return;
 }
 node *temp=*head,*prev;
 if(pos==0)
 {
  *head=(*head)->next;
  free(temp);
  return;
 }
 int i=0;
 while(temp!=NULL && i<pos)
 {
  prev=temp;
  temp=temp->next;
  i++;
 }
 if(temp==NULL)
 {
  printf("Invalid Position\n");
  return ;
 }
 prev->next=temp->next;
 free(temp);
 return;
 
}

int main()
{
node *start=NULL;
int i,n;
for(i=0;i<2;i++)
 InsertEnd(&start,i);
printList(start);
/*
while(1)
{
printf("\nEnter Number to Delete:");
scanf("%d",&n);
DeleteNode(&start,n);
printList(start);
printf("\n");
}*/
while(1)
{
 printf("\nEnter Position of the Element:");
 scanf("%d",&n);
 DeletePosition(&start,n);
 printList(start);
}
return 0;
}
