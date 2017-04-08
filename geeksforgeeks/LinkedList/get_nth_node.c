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
 return ;
}

void printList(node *head)
{
 if(head==NULL)
 {
  printf("\nList Empty");
  return ;
 }
 while(head!=NULL)
 {
  printf("%d->",head->num);
  head=head->next;
 }
 return ; 
}

int getNth(node *start,int pos)
{
 if(start==NULL)
 {
  return ;
 }
 int count=0;
 while(start!=NULL && count<pos)
 {
  count+=1;
  start=start->next;
 }
 if(start==NULL)
 {
   printf("\nInvalid Position");
   return ;
 }
 return start->num;
}

int main()
{
 node *start=NULL;
 int i;
 for(i=0;i<100;i++)
  insertEnd(&start,i);
 printList(start);
 int pos;
 printf("\nEnter position: ");
 scanf("%d",&pos);
 printf("\nElement is: %d\n",getNth(start,pos));
 return 0;
}
