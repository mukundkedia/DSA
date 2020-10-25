//https://leetcode.com/problems/merge-two-binary-trees/
//PC

class Solution {
public:
    TreeNode* solve(TreeNode* t1,TreeNode* t2){
        if(t1==NULL and t2==NULL){
            return NULL;
        }
        if(!t1){
            return t2;
        }
        if(!t2){
            return t1;
        }
        t1->val = t1->val + t2->val;
        t1->left = solve(t1->left,t2->left);
        t1->right = solve(t1->right,t2->right);
        return t1;
    }
    
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL and t2==NULL){
            return NULL;
        }
        return solve(t1,t2);
    }
};