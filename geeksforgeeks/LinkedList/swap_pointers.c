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

void swamp(node **head,int a,int b)
{
 
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
 return 0;
}
