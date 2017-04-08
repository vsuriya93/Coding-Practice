/*
  Insert Node at the end of a linked list 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Insert(Node *head,int data)
{
  // Complete this method
    struct Node *element=(Node *)malloc(sizeof(struct Node));
    element->data=data;
    element->next=NULL;
    if(head==NULL)
        {
        head=element;
        return head;
    }
    Node *temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=element;
    return head;
}

