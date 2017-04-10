#include<stdio.h>
#include<malloc.h>

#define true 1
#define false 0

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

node * reverseList(node *head)
{
 if(head==NULL || head->next==NULL)
	return head;
 node *prev=NULL,*curr=head,*nxt=curr;
 while(curr!=NULL)
 {
  nxt=curr->next;
  curr->next=prev;
  prev=curr;
  curr=nxt;
 }
 return prev;
}

int checkPalindrome(node *a)
{
}

int main()
{
 node *start=NULL;
 int i;
 insertEnd(&start,5);
 insertEnd(&start,11);
 insertEnd(&start,12);
 insertEnd(&start,13);
 insertEnd(&start,14);
 printList(start);
 printf("\n");
 printf("\n%d\n",checkPalindrome(start));
 return 0;
}
