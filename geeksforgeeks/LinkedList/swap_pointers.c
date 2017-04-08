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
 printf("\n");
 return ;
}

int find_pos(node *head,int num, node **loc)
{
 int pos=0;
 if(head==NULL)
 {
  return -1;
 }
 while(head!=NULL && head->num!=num)
 {
  pos+=1;
  *loc=head;
  head=head->next;
 }
 if(head==NULL)
 {
  return -1;
 }
 return pos;
}

void swap(node **head,int a,int b)
{
 int pos_a,pos_b;
 if (a==b)
  return;
 
 node *p_x=NULL,*c_x=*head,*p_y=NULL,*c_y=*head;
 while(c_x!=NULL && c_x->num!=a)
 {
  p_x=c_x;
  c_x=c_x->next;
 }
 while(c_y!=NULL && c_y->num!=b)
 {
  p_y=c_y;
  c_y=c_y->next;
 }

 if(c_x == NULL || c_y==NULL) //element not found
  return ;

 if(p_x==NULL) //if pos_a = 0
  *head=c_y;
 else
  p_x->next=c_y;

 if(p_y==NULL)
  *head=c_x;
 else
  p_y->next=c_x;

 node *temp=c_x->next;
 c_x->next=c_y->next;
 c_y->next=temp;
 return;
}

int main()
{
 node *start=NULL;
 int i,a[]={1,2,3,4,5};
 for(i=0;i<5;i++)
  insertEnd(&start,a[i]);
 printList(start);
 int num1,num2;
 printf("\nEnter Elements to be swapped: ");
 scanf("%d%d",&num1,&num2);
 swap(&start,num1,num2);
 printList(start);
 return 0;
}
