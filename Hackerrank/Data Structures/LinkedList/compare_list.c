/*
  Compare two linked lists A and B
  Return 1 if they are identical and 0 if they are not. 
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/
int CompareLists(Node *headA, Node* headB)
{
  // This is a "method-only" submission. 
  // You only need to complete this method 
    if(headA==NULL && headB==NULL)
        {
        return 1;
    }
    else if(headA==NULL && headB!=NULL)
        {
        return 0;
    }
    else if(headB==NULL && headA!=NULL)
        {
        return 0;
    }
    else
        {
        Node *itr_a=headA,*itr_b=headB;
        while(itr_a!=NULL && itr_b!=NULL)
            {
            if(itr_a->data!=itr_b->data)
                return 0;
            itr_a=itr_a->next;
            itr_b=itr_b->next;
        }
        if(itr_a==NULL && itr_b==NULL)
            return 1;
        else
            return 0;
    }
}

