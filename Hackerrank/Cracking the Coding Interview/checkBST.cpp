/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
   struct Node {
      int data;
      Node* left;
      Node* right;
   }
*/
vector<int> arr;

bool check_sorted(vector<int> arr){
    for(int i=1,j=0;i<arr.size();i++,j++){
        if(arr[j]>=arr[i])
            return false;
    }
    return true;
}

   bool checkBST(Node* root) {
       static bool flag=false;
       if(root!=NULL){
       checkBST(root->left);
       arr.push_back(root->data);
       flag=check_sorted(arr);
       checkBST(root->right);
       if(flag==false)
           return false;
       else
           return true;
     }
       else
           {
           return true;
       }
   }

