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

void detectLoop(node *start)
{
 if(start==NULL)
  return;
 node *slow=start,*fast=start;
 while(fast!=NULL && slow!=NULL && fast->next!=NULL)
 {
  slow=slow->next;
  fast=fast->next->next;
  if(slow==fast)
  {
    printf("\nLoop Detected\n");
    return;
  }
 }
 printf("\nNo Loop\n");
}

int main()
{
 node *start=NULL;
 int i;
 for(i=0;i<4;i++)
  insertEnd(&start,i+1);
 printList(start);
// start->next->next->next->next=start;
 detectLoop(start); 
 return 0;
}
