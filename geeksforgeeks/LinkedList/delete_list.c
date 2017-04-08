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
 return ; 
}

void deleteList(node **head)
{
 node *temp=*head;
 while(*head!=NULL)
 {
  *head=(*head)->next;
  free(temp);
  temp=*head;
 }
 return ;
}

int main()
{
 node *start=NULL;
 int i;
 for(i=0;i<10;i++)
  insertEnd(&start,i+1);
 printList(start);
 deleteList(&start);
 printList(start);
 return 0;
}
