
/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

int height(node *root){
    if(root==NULL)
        return 0;
    int left=height(root->left),right=height(root->right);
    if(left>right)
        return left+1;
    else
        return right+1;
}

void printLevelNodes(node *root,int level)
    {
    if(root==NULL)
       return;
    if(level==1)
        cout<<root->data<<" ";
    else{
        printLevelNodes(root->left,level-1);
        printLevelNodes(root->right,level-1);
    }
        
    
}

void LevelOrder(node * root)
{
  int h=height(root),i;
  for(i=1;i<=h;i++)
      printLevelNodes(root,i);
  
}

