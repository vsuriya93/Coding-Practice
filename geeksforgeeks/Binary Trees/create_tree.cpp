#include<iostream>
using namespace std;

class node
{
 public:
 	int data;
	class node *left;
	class node *right;
	node();
	node(int num)
	{
	 data=num;
	 left=NULL;
	 right=NULL;
	}
 	
};

int main()
{
 node *root=new node(5);
 root->left=new node(6);
 root->right=new node(7);
 node *temp=root->left;
 cout<<temp->data;
 return 0;
}
