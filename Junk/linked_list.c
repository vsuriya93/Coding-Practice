#include<stdio.h>
#include<malloc.h>

struct node
{
int num;
struct node* next;
};

typedef struct node node;

node* create_node(int num)
{
node *element=malloc(sizeof(node));
element->num=num;
element->next=NULL;
return element;
}

node* insert_end(node *start,int num)
{
if(start==NULL)
 {
  node *element=create_node(num);
  start=element;
 }
else
 {
  node *temp=start;
  while(temp->next!=NULL)
   temp=temp->next;
  node *element=create_node(num);
  temp->next=element;
 }
 return start;
}

node* insert_begin(node *start,int num)
{
 if(start==NULL)
 {
 node *element=create_node(num);
 start=element;
 }
 else
 {
  node *element=create_node(num);
  element->next=start;
  start=element;
 }
 return start;
}

node* insert_middle(node *start,int num)
{
 if(start==NULL)
 {
  node *element=create_node(num);
  start=element;
 }
 else
 {
 node *prev=start,*itr=start;
 node *element=create_node(num);
 if(start->num >= num)
 {
  element->next=start;
  start=element;
 }
 else
 {
  while(itr->num < num && itr->next!=NULL)
  {
   prev=itr;
   itr=itr->next;
  }

   if(itr->next==NULL && itr->num<=num) // handling for last-element case
   {
    itr->next=element;
   }
   else
   {
   element->next=itr;
   prev->next=element;
   }
  }
 }
 return start;
}

void print(node *start)
{
 node *temp=start;
 while(temp!=NULL)
 {
  printf("%d->",temp->num);
  temp=temp->next;
 }
 printf("\n");
}

int main()
{
node *start=NULL;
int num;
while(1)
{
 printf("\nEnter Value:");
 scanf("%d",&num);
// start=insert_end(start,num);
// start=insert_begin(start,num);
 start=insert_middle(start,num);
 print(start);
}
return 0;
}
