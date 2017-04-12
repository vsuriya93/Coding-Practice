/* Program to remove duplicates in an unsorted
linked list */
#include<stdio.h>
#include<malloc.h>

/* A linked list node */
struct Node
{
	int data;
	struct Node *next;
};

typedef struct Node Node;

// Utility function to create a new Node
struct Node *newNode(int data)
{
Node *temp = (Node*)malloc(sizeof(Node));
temp->data = data;
temp->next = NULL;
return temp;
}

/* Function to remove duplicates from a
unsorted linked list */
void removeDuplicates(struct Node *start)
{
 if(start==NULL || start->next==NULL)
   return ;
 Node *curr=start,*runner,*prev,*temp;
 while(curr!=NULL)
 {
  prev=curr;
  runner=curr->next;
  while(runner!=NULL)
  {
   if(runner->data==curr->data)
   {
    temp=runner;
    prev->next=runner->next;
    runner=runner->next;
    free(temp);
    continue;
   }
   prev=runner;
   runner=runner->next;
  }
  curr=curr->next;
 }
 return ;
}

/* Function to print nodes in a given linked list */
void printList(struct Node *node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

/* Druver program to test above function */
int main()
{
	/* The constructed linked list is:
	10->12->11->11->12->11->10*/
	struct Node *start = newNode(10);
	start->next = newNode(12);
	start->next->next = newNode(11);
	start->next->next->next = newNode(11);
	start->next->next->next->next = newNode(12);
	start->next->next->next->next->next =
									newNode(11);
	start->next->next->next->next->next->next =
									newNode(10);

	printf("Linked list before removing duplicates ");
	printList(start);

	removeDuplicates(start);

	printf("\nLinked list after removing duplicates ");
	printList(start);

	return 0;
}

