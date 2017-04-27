#include<iostream>
#include<stack>

using namespace std;

struct node
{
 int num;
 struct node *left,*right;
};

typedef struct node node;

node * createNode(int n)
{
 node *element=new node;
 element->num=n;
 element->left=element->right=NULL;
 return element;
}

node * insert(node *root,int el)
{
 if(root==NULL)
 {
  root=createNode(el);
  return root;
 }
 if(el <  root->num)
 {
  root->left=insert(root->left,el);
 }
 if(el > root->num)
 {
  root->right=insert(root->right,el);
 }
 return root;
}

void inorder(node *root)
{
 if(root==NULL)
  return;
 inorder(root->left);
 cout<<root->num<<"->";
 inorder(root->right);
}

void inorder_stack(node *root)
{
 stack<node *> s;
 node *element=root;
 while(1)
 {
  if(element!=NULL)
  {
   s.push(element);
   element=element->left;
  }
  else
  {
   if(element==NULL && !s.empty())
   {
   element=s.top();
   s.pop();
   cout<<element->num<<"->";
   element=element->right;
   }
   if(element==NULL && s.empty())
    break;
  }
 }
 cout<<endl;
}

int main()
{
  node *root=NULL;
  root=insert(root,5);
  root=insert(root,3);
  root=insert(root,2);
  root=insert(root,4);
  root=insert(root,7);
  root=insert(root,6);
  root=insert(root,8);
  inorder_stack(root);
}
