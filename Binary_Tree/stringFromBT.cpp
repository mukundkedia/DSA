//https://leetcode.com/problems/construct-string-from-binary-tree/
//PC

#include<bits/stdc++.h> 
using namespace std; 
  
struct TreeNode 
{ 
    int val; 
    TreeNode *left, *right; 
}; 
  
//New node of a tree 
TreeNode *newNode(int data) 
{ 
    TreeNode *node = new TreeNode; 
    node->val = data; 
    node->left = node->right = NULL; 
    return node; 
} 

void solve(TreeNode* root,string& ans){
        if(!root){
            return;
        }
        if(!root->left and !root->right){
            ans+=to_string(root->val);
            
            return;
        }
        ans+=to_string(root->val);
        ans+='(';
        solve(root->left,ans);
        ans+=')';
        if(root->right){
        ans+='(';
        solve(root->right,ans);
        ans+=')';
    }
    }
    
    string tree2str(TreeNode* t) {
        string ans="";
        solve(t,ans);
        return ans;
    }

    int main() 
{ 
    // Let us create tree shown in third example 
    struct TreeNode *root = newNode(12); 
    root->left = newNode(5); 
    root->left->left = newNode(3); 
    root->left->right = newNode(9); 
    root->left->left->left = newNode(1); 
    root->left->right->left = newNode(1); 
    cout<<tree2str(root);
}