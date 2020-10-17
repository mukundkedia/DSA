// https://leetcode.com/problems/maximum-width-of-binary-tree/
// PC
// TBW


class Solution {
public:
    #define ll unsigned long long
    
    
    ll dfs(TreeNode* root,ll level,ll id, unordered_map<ll,ll>& map1){
        if(!root){
            return 0;
        }
        if(map1.find(level)==map1.end()){
            map1[level]=id;
        }
       ll curr = id-map1[level]+1;
        ll l = dfs(root->left,level+1,2*id,map1);
        ll r = dfs(root->right,level+1,2*id+1,map1);
        return max(curr,max(l,r));
    }
    
    ll widthOfBinaryTree(TreeNode* root) {
        ll level=0;
        ll id=1;
        unordered_map<ll,ll> map1;
        return dfs(root,level,id,map1);
    }
};