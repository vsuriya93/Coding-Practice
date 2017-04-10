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

void shiftPointers(node **dest,node **source)
{
 node *newNode=*source;
 if(newNode==NULL)
  return ;
 *source=(*source)->next;
 newNode->next=*dest;
 *dest=newNode;
}

node * sortedMerge(node *a,node *b)
{
 node dummy;
 node *tail=&dummy;
 dummy.next=NULL;
 while(1)
 {
  if(a==NULL)
  {
   tail->next=b;
   break;
  }
  else if(b==NULL)
  {
   tail->next=a;
   break;
  }
  else
  {
   if(a->num <= b->num)
   {
    shiftPointers(&(tail->next),&a);
   }
   else
   {
    shiftPointers(&(tail->next),&b);
   }
  }
  tail=tail->next;
 }
 return dummy.next;
}

int main()
{
 node *a=NULL,*b=NULL,*result;
 int i;
 insertEnd(&a,5);
 insertEnd(&a,10);
 insertEnd(&a,15);
 insertEnd(&b,2);
 insertEnd(&b,3);
 insertEnd(&b,20);
 printList(a);
 printf("\n");
 printList(b);
 printf("\n");
 result=sortedMerge(a,b);
 printList(result);
 printf("\n");
 return 0;
}
