#include<iostream>
using namespace std;

struct node
{
 int data;
 struct node *left;
 struct node *right;
};

typedef struct node node;

node * createNode(int num)
{
 node *element=new node;
 element->data=num;
 element->left=NULL;
 element->right=NULL;
 return element;
}

void inorder(node *root)
{
 if(root==NULL)
  return ;
 inorder(root->left);
 cout<<root->data<<"->";
 inorder(root->right);
}

void preorder(node *root)
{
 if(root==NULL)
  return ;
  cout<<root->data<<"->";
  preorder(root->left);
  preorder(root->right);
}

void postorder(node *root)
{
 if(root==NULL)
  return;
 postorder(root->left);
 postorder(root->right);
 cout<<root->data<<"->";
}

int height(node *root)
{
 if(root==NULL)
  return 0;
 else
 {
  int l=height(root->left);
  int r=height(root->right);
//  cout<<root->data<<" "<<l<<" "<<r<<"\n";
  if(l>r)
   return l+1;
  else
  return r+1;
 }
}

void printLevel(node *root,int level);
void printLevelOrder(node *root)
{
 int i,h=height(root);
 for(i=1;i<=h;i++)
  printLevel(root,i);
 return ;
}

void printLevel(node *root,int level)
{
 if(root==NULL)
  return ;
 if (level==1)
   cout<<root->data<<"->";
 else
    printLevel(root->left,level-1);
    printLevel(root->right,level-1);

}

int main()
{
 node *root=createNode(5);
 root->left=createNode(3);
 root->right=createNode(6);
 root->left->left=createNode(2);
 root->left->right=createNode(4);
 cout<<"Inorder: ";
 inorder(root);
 cout<<"\nPreorder: ";
 preorder(root);
 cout<<"\nPost-order: ";
 postorder(root);
 cout<<"\n";
 printLevelOrder(root);
}
