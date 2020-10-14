// https://leetcode.com/problems/diameter-of-binary-tree/
// PC

class Solution {
public:
    int solve(TreeNode* root,int &ans){
        if(!root){
            return 0;
        }
        int l = solve(root->left,ans);
        int r = solve(root->right,ans);
        ans = max(ans,l+r);
        return max(l,r)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=0;
        solve(root,ans);
        return ans;
    }
};