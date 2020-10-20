//https://leetcode.com/problems/find-duplicate-subtrees/
//PC

class Solution {
public:
    vector<TreeNode*> vec;
    string dup(TreeNode* root,unordered_map<string,int> &map1){
        if(!root){
            return "#";
        }
        string l = dup(root->left,map1);
        string r = dup(root->right,map1);
        string temp = l+","+r+","+to_string(root->val)+",";
        map1[temp]++;
        if(map1[temp]==2){
            vec.push_back(root);
        }
        return temp;
    }
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        
        unordered_map<string,int> map1;
        dup(root,map1);
        return vec;
    }
};