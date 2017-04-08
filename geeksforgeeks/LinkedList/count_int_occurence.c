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

int countOccurence(node *head,int i)
{
 int count=0;
 while(head!=NULL)
 {
  if(head->num==i)
	count+=1;
  head=head->next;
 }
 return count;
}

int main()
{
 node *start=NULL;
 int i;
 for(i=0;i<10;i++)
  insertEnd(&start,i);
 printList(start);
 printf("\nEnter number: ");
 scanf("%d",&i);
 printf("\nOccurence = %d\n",countOccurence(start,i));
 return 0;
}
