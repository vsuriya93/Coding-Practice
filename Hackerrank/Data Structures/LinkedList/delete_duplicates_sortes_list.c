/*
  Remove all duplicate elements from a sorted linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
Node* RemoveDuplicates(Node *head)
{
  // This is a "method-only" submission. 
  // You only need to complete this method. 
    if(head==NULL || head->next==NULL)
        return head;
    Node *curr=head,*runner=head->next,*temp;
    while(runner!=NULL)
        {
        if(curr->data==runner->data)
            {
           //printf("%d %d\n",curr->data,runner->data) ;
           temp=runner;
            runner=runner->next;
            curr->next=runner;
            free(temp);
        }
        else
            {
            curr=curr->next;
            runner=runner->next;
        }
        //runner=runner->next;
    }
   return head;
}

