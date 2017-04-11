/*
   Find merge point of two linked lists
   Node is defined as
   struct Node
   {
       int data;
       Node* next;
   }
*/

int getLength(Node *head)
{
    int count=0;
    while(head){
        count+=1;
        head=head->next;
    }
    return count;
}

void printList(Node *head)
    {
    while(head)
        {
        cout<<head->data<<"->";
        head=head->next;
    }
    cout<<"\n";
}

int FindMergeNode(Node *head1, Node *head2)
{
    // Your Code Here
    int len1=getLength(head1),len2=getLength(head2);
    int diff=len1-len2;
   // cout<<"Diff: "<<diff;
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
    //printList(head1);
    //printList(head2);
    //cout<<" \nData:"<<head1->data<<" "<<head2->data<<"\n";
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

