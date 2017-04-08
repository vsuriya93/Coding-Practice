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
 node *element=(node*)malloc(sizeof(node));
 element->num=num;
 element->next=NULL;
 return element;
}

void insertBegin(node **head,int num)
{
 if(*head==NULL)
 {
  (*head)=create_node(num);
  return ;
 }
 else
 {
  node *element=create_node(num);
  element->next=(*head);
  *head=element;
  return ;
 }
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

void double_pointer_deleteFirst(node **head)
{
 if(*head==NULL)
 {
  printf("\nList Empty");
  return ;
 }
 node *temp=*head;
 *head=(*head)->next;
 free(temp);
 return ;
}

node * return_head_deleteFirst(node *start)
{
 if(start==NULL)
 {
  printf("\nList Empty");
  return start;
 }
 node *temp=start;
 start=start->next;
 free(temp);
 return start;
}

node *global_start=NULL;

void global_head_deleteFirst()
{
 if(global_start==NULL)
 {
  printf("\nList Empty");
  return ;
 }
 node *temp=global_start;
 global_start=global_start->next;
 free(temp);
}

int main()
{
 node *start=NULL;
 int i;
 for(i=0;i<100;i++)
  {
   insertBegin(&start,i);
   insertBegin(&global_start,i);
  }

 printList(global_start);

 double_pointer_deleteFirst(&start);
 start=return_head_deleteFirst(start);
 global_head_deleteFirst();
 
 return 0; 
}
