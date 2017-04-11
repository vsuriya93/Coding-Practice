/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if(head==NULL || head->next==NULL)
        return false;
    Node *slow=head,*fast=head;
    while(fast!=NULL && fast->next!=NULL)
        {
        fast=fast->next->next;
        if(fast==slow)
            {
            return true;
        }
        slow=slow->next;
    }
    return false;
}

