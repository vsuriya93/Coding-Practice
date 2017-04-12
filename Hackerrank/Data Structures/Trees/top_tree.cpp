/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void top_view(node * root)
{
 if(root==NULL)
     return;
 static int level=0,go_left=1;
 level+=1;
 if(go_left){
 top_view(root->left);
}
 level=level-1;
 cout<<root->data<<" ";
 if(level==0){
     go_left=0;
     top_view(root->right);
 }
}

