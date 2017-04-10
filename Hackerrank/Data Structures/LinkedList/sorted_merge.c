/*
  Merge two sorted lists A and B as one linked list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

void modifyPointers(Node **dest,Node **src)
    {
    Node *newNode=*src;
    if(newNode==NULL)
        return;
    *src=(*src)->next;
    newNode->next=*dest;
    *dest=newNode;
}

Node* MergeLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method
    Node dummy;
    Node *tail=&dummy;
    dummy.next=NULL;
    while(1)
        {
        if(headA==NULL)
            {
            tail->next=headB;
            break;
        }
        else if(headB==NULL)
            {
            tail->next=headA;
            break;
        }
        else if(headA->data<=headB->data)
            {
            modifyPointers(&(tail->next),&headA);
        }
        else
            {
            modifyPointers(&(tail->next),&headB);
        }
        tail=tail->next;
    }
    return dummy.next;
}

