//https://leetcode.com/problems/path-sum-iii/
  
  void solve(TreeNode* root,int sum,int &count,vector<int> &path){
        if(!root){
            return;
        }
        path.push_back(root->val);
        solve(root->left,sum,count,path);
        solve(root->right,sum,count,path);
        int f=0;
        for(int i=path.size()-1;i>=0;i--){
            f+=path[i];
            if(f==sum){
                count++;
            }
        }
        path.pop_back();
    }
    
    int pathSum(TreeNode* root, int sum) {
        int count=0;
        vector<int> path;
        solve(root,sum,count,path);
        return count;
    }