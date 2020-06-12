class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> result;
        if (root==NULL){
            return result;
        }
        q.push(root);
        TreeNode *temp = NULL;
        vector<int> level_sum;
        int s = 0;
        while(!q.empty()){
            s = q.size();
            for (int j=0; j<s;j++){
                temp = q.front();
                level_sum.push_back(temp->val);
                if (temp->left !=NULL){
                    q.push(temp->left);
                    }
                if(temp->right!=NULL){
                    q.push(temp->right);
                    }
                 q.pop();
            }
            result.push_back(level_sum);
            level_sum.clear();
        }
        return result;
    }
};
