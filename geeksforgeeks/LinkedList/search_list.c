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

int search_iter(node *head,int key)
{
 if(head==NULL)
 {
  printf("\nEmpty List - Element not Found\n");
  return -1;
 }
 if(head->num==key)
 {
  return 0;
 }
 int pos=0;
 while(head!=NULL && head->num!=key)
 {
  head=head->next;
  pos+=1;
 }
 if(head==NULL)
 {
  printf("\nElement Not Found");
  return -1;
 }
 return pos;
}

int search_rec(node *head,int num)
{
 static int pos=0;
 if(head==NULL)
 {
  return -1;
 }
 else
 {
  if(head->num==num)
   return pos;
  pos+=1;
  pos=search_rec(head->next,num);
  return pos;
 }
}

int main()
{
node *start=NULL;
int n,i;
for(i=0;i<100;i++)
 InsertBegin(&start,i);
printList(start);
printf("\n");
printf("Enter Key for Search:");
scanf("%d",&n);
printf("\nPosition is %d\n",search_rec(start,n));
return 0;
}
