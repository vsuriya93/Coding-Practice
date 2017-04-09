#include<stdio.h>
#include<malloc.h>

struct node
{
 int num;
 struct node *next;
};

typedef struct node node;

node * create_node(int num)
{
 node *element=(node *)malloc(sizeof(node));
 element->num=num;
 element->next=NULL;
 return element;
}

void insertEnd(node **head,int num)
{
 if(*head==NULL)
 {
  *head=create_node(num);
  return;
 }
 node *temp=*head;
 while(temp->next!=NULL)
  temp=temp->next;
 node *element=create_node(num);
 temp->next=element;
}

void printList(node *head)
{
 if(head==NULL)
 {
  printf("\nList Empty\n");
  return ;
 }
 while(head!=NULL)
 {
  printf("%d->",head->num);
  head=head->next;
 }
 printf("\n");
 return ; 
}

node * reverse_list(node *head)
{
 if(head==NULL || head->next==NULL)
 {
  return head;
 }
 node *prev=NULL,*curr=head,*nxt=head;
 while(nxt!=NULL)
 {
  nxt=curr->next;
  curr->next=prev;
  prev=curr;
  curr=nxt;
 }
 return prev;
}

int main()
{
 node *start=NULL;
 int i;
 for(i=0;i<10;i++)
  insertEnd(&start,i+1);
 printList(start);
 start=reverse_list(start);
 printList(start);
 return 0;
}
