/* Link list Node 
struct Node {
    int data;
    struct Node* next;
}; */


/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */

int getLength(Node *head)
{
    int count=0;
    while(head){
        count+=1;
        head=head->next;
    }
    return count;
}

int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int len1=getLength(head1),len2=getLength(head2);
    int diff=len1-len2;
    if (diff>0){
        while(diff--){
            head1=head1->next;
        }
    }
    else
    {
        while(diff++){
            head2=head2->next;
        }
    }
    while(head1 && head2){
        if(head1==head2)
        {
            return head1->data;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return -1;
}
