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

void reverseList(node **head)
{
 if(*head==NULL || (*head)->next==NULL)
	return ;
 node *prev=NULL,*curr=*head,*nxt;
 while(curr!=NULL)
 {
  nxt=curr->next;
  curr->next=prev;
  prev=curr;
  curr=nxt;
 }
 *head=prev;
}

int compare(node *a,node *b)
{
 node *t1=a,*t2=b;
 while(t1 && t2)
 {
  if(t1->num!=t2->num)
   return 0;
  t1=t1->next;
  t2=t2->next;
 }
 return 1;
}

int checkPalindrome(node *head)
{
 if(head==NULL | head->next==NULL)
 	return 0;
 node *fast=head,*slow=head,*prev=head,*mid=NULL;
 while(fast!=NULL && fast->next!=NULL)
 {
  prev=slow;
  slow=slow->next;
  fast=fast->next->next;
 }
 
 if(fast!=NULL) //saving mid val for odd len list
 {
  mid=slow;
  slow=slow->next;
 }
 node *second_list=slow;
 prev->next=NULL;
 reverseList(&second_list);
 int result=compare(head,second_list);
 reverseList(&second_list);
 if(mid!=NULL)
 {
  prev->next=mid;
  mid->next=second_list;
 }
 else
  prev->next=second_list;
 return result;
}

int main()
{
 node *start=NULL;
 int i;
 insertEnd(&start,5);
 insertEnd(&start,11);
 insertEnd(&start,12);
 insertEnd(&start,12);
 insertEnd(&start,11);
 insertEnd(&start,5);
 printList(start);
 printf("\n");
 printf("\n%d\n",checkPalindrome(start));
 printList(start);
 return 0;
}
