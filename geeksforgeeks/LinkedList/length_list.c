#include<stdio.h>
#include<malloc.h>

struct node
{
int num;
struct node *next;
};

typedef struct node node;

node* create_node(int n)
{
 node *temp=malloc(sizeof(node*));
 temp->num=n;
 temp->next=NULL;
 return temp;
}

void printList(node *tmp)
{
 if(tmp==NULL)
 {
  printf("\nEmpty List\n");
  return ;
 }
 while(tmp!=NULL)
 {
  printf("%d->",tmp->num);
  tmp=tmp->next;
 }
}

void InsertBegin(node** head,int n)
{
 node *new_node=create_node(n);
 new_node->next=*head;
 (*head)=new_node;
}

void InsertAfter(node *prev,int n)
{
 node *new_node=create_node(n);
 new_node->next=prev->next;
 prev->next=new_node;
}

void InsertEnd(node **start,int n)
{
 node *new_node=create_node(n);
 if((*start)==NULL)
 {
  (*start)=new_node;
  return ;
 }
 node *temp=(*start);
 while(temp->next!=NULL)
  temp=temp->next;
 temp->next=new_node;
 return ;
}

int length_iter(node *head)
{
 int length=0;
 while(head!=NULL)
 {
  length+=1;
  head=head->next;
 }
 return length;
}

int length_rec(node *head)
{
 if(head==NULL)
 {
  return 0;
 }
 else
 {
  return 1+length_rec(head->next);
 }
}

int main()
{
node *start=NULL;
int n,i;
//for(i=0;i<10;i++)
// InsertBegin(&start,i);
printList(start);
printf("\n");
printf("Length: %d\n",length_rec(start));
return 0;
}
