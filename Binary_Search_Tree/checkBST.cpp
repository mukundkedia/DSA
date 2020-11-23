//https://leetcode.com/problems/validate-binary-search-tree/

class Solution {
public:
    int util(TreeNode* root,long long mini,long long maxi){
    if(!root){
        return 1;
    }
    if(root->val<mini || root->val>maxi){
        return 0;
    }
    return util(root->left,(long long)mini,(long long)root->val-1) and util(root->right,(long long)root->val+1,(long long)maxi);
}
    
    bool isValidBST(TreeNode* root) {
        return util(root,(long long)INT_MIN,(long long)INT_MAX);
    }
};