/*
  Get Nth element from the end in a linked list of integers
  Number of elements in the list will always be greater than N.
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int GetNode(Node *head,int positionFromTail)
{
  // This is a "method-only" submission. 
  // You only need to complete this method.
    int count=0;
    Node *pos=head;
    while(count++<positionFromTail)
        head=head->next;
    while(head->next!=NULL){
        head=head->next;
        pos=pos->next;
    }
    return pos->data;
}

