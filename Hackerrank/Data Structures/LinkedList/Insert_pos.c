/*
  Insert Node at a given position in a linked list 
  head can be NULL 
  First element in the linked list is at position 0
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* InsertNth(Node *head, int data, int position)
{
  // Complete this method only
  // Do not write main function. 
    Node *element=(struct Node *)malloc(sizeof(struct Node));
    element->data=data;
    element->next=NULL;
    
    if(head==NULL)
        {
        head=element;
        return head;
    }
    if (position==0)
        {
        element->next=head;
        head=element;
        return head;
    }
    int count=1;
    struct Node *temp=head;
    while(temp!=NULL && count<position)
        {
        count+=1;
        temp=temp->next;
    }
    if(temp==NULL)
        {
        return temp;
    }
    element->next=temp->next;
    temp->next=element;
    return head;
    
    
}

