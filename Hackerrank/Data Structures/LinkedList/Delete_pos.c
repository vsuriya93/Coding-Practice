/*
  Delete Node at a given position in a linked list 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* Delete(Node *head, int position)
{
  // Complete this method
    Node *temp=head,*prev;
    if (position==0)
        {
        head=head->next;
        free(temp);
        return head;
    }
    int count=0;
    while(temp!=NULL && count<position)
        {
        prev=temp;
        temp=temp->next;
        count+=1;
    }
    if(temp==NULL){
        printf("Invalid Position Value");
    }
    prev->next=temp->next;
    free(temp);
    return head;
}

