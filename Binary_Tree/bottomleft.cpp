//   https://leetcode.com/problems/find-bottom-left-tree-value/
//     PC
  int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* ans;
        while(!q.empty()){
            ans = q.front();
            int len = q.size();
            while(len>0){
                TreeNode* temp = q.front();
                        q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                len--;
            }
        }
        return ans->val;
    }