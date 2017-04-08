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

int get_nth_node_from_end(node *head,int n)
{
 int count=0;
 node *nth_node=head;
 while(count<n)
 {
  if(head==NULL)
  {
   printf("\nInvalid input\n");
   return ;
  }
  count+=1;
  head=head->next;
 }
 while(head!=NULL)
 {
  head=head->next;
  nth_node=nth_node->next;
 }
 return nth_node->num;
}

void get_nth_node_from_end_rec(node *head,int n)
{
 static int i=0;
 if(head==NULL)
 {
  return ;
 }
 get_nth_node_from_end_rec(head->next,n);
 if(++i==n)
 {
  printf("Node is: %d\n", head->num);
 }
}

int main()
{
 node *start=NULL;
 int i;
 for(i=0;i<10;i++)
  insertEnd(&start,i+1);
 printList(start);
 printf("\nEnter N: ");
 scanf("%d",&i);
// printf("\nNode is : %d\n",get_nth_node_from_end_rec(start,i));
 get_nth_node_from_end_rec(start,i);
 return 0;
}
