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

int get_middle(node *head)
{
  if(head!=NULL)
  {
   node *slow=head,*fast=head;
   while(fast!=NULL && fast->next!=NULL)
   {
    slow=slow->next;
    fast=fast->next->next;
   }
   return slow->num;
  }
}

int main()
{
 node *start=NULL;
 int i;
 for(i=0;i<1;i++)
  insertEnd(&start,i+1);
 printList(start);
 printf("\nMiddle is : %d\n",get_middle(start));
 return 0;
}
