#include<iostream>
using namespace std;

struct node
{
 int data;
 struct node *left,*right;
};

typedef struct node node;

node *createNode(int num)
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

void mirror_tree(node *root)
{
 if(root==NULL)
  return;
 mirror_tree(root->left);
 mirror_tree(root->right);
 if(root->left!=NULL || root->right!=NULL)
 {
  node *temp=root->left;
  root->left=root->right;
  root->right=temp;
 }
}

int main()
{
 node *root=createNode(1);
 root->left=createNode(2);
 root->right=createNode(3);
 root->left->left=createNode(4);
 root->left->right=createNode(5);
 inorder(root);
 cout<<"\n";
 mirror_tree(root);
 inorder(root);
 cout<<"\n";
}
