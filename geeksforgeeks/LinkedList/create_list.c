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

node* insert(node *start,int n)
{
if(start==NULL)
{
 start=create_node(n);
 return start;
}

node *temp=start;
while(temp->next!=NULL)
{
 temp=temp->next;
}
node *new_node=create_node(n);
temp->next=new_node;
return start;
}

void printList(node *tmp)
{
 while(tmp!=NULL)
 {
  printf("%d->",tmp->num);
  tmp=tmp->next;
 }
}

int main()
{
node *start=NULL;
int n;
while(1)
{
 printf("Enter Number:");
 scanf("%d",&n);
 start=insert(start,n);
 printList(start);
 printf("\n");
}
return 0;
}
