#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
    int data;
    struct node* next;
};
 
typedef struct node node;

node * newNode(int num)
{
 node *element=(node*)malloc(sizeof(node));
 element->data=num;
 element->next=NULL;
 return element;
}

void sortedInsert(struct node** head_ref, struct node* new_node)
{
 if(*head_ref==NULL)
 {
  *head_ref=new_node;
  return ;
 }
 if(new_node->data < (*head_ref)->data)
 {
  new_node->next=(*head_ref);
  *head_ref=new_node;
  return;
 }
 node *prev=*head_ref,*runner=(*head_ref)->next;
 while(runner!=NULL && runner->data<new_node->data)
 {
  prev=runner;
  runner=runner->next;
 }
 if(runner==NULL)
 {
  prev->next=new_node;
 }
 else
 {
  prev->next=new_node;
  new_node->next=runner;
 }
 return ;
}
 
 
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
 
/* Drier program to test count function*/
int main()
{
    /* Start with the empty list */
    struct node* head = NULL;
    struct node *new_node = newNode(5);

    sortedInsert(&head, new_node);
    new_node = newNode(10);
    sortedInsert(&head, new_node);
    new_node = newNode(7);
    sortedInsert(&head, new_node);
    new_node = newNode(3);
    sortedInsert(&head, new_node);
    new_node = newNode(1);
    sortedInsert(&head, new_node);
    new_node = newNode(9);
    sortedInsert(&head, new_node);
    printf("\n Created Linked List\n");
/*    int i;
    for(i=0;i<200;i++)
     sortedInsert(&head,newNode(rand()%20));*/
    printList(head);
 
    return 0;
}
