
/*The tree node has data, left child and right child 
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
    int height(Node* root) {
        // Write your code here.
        if(root==NULL)
            return -1;
        int left=height(root->left),right=height(root->right);
        if (left>right)
            return left+1;
        else
            return right+1;
    }
  
