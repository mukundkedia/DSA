// https://www.geeksforgeeks.org/find-largest-subtree-sum-tree/
// PC
// https://sapphireengine.com/@/no72xh

#include<bits/stdc++.h> 
using namespace std; 
  
struct Node 
{ 
    int data; 
    Node *left, *right; 
}; 
  
//New node of a tree 
Node *newNode(int data) 
{ 
    Node *node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
} 


void preorder(Node* root){
    if(!root){
        return;
    }
    cout<<root->data<<" ";
   preorder(root->left);
   preorder(root->right);
    }

int solve(Node* root,int &res){
    if(!root){
        return 0;
    }
   	int lsum = solve(root->left,res);
    int rsum = solve(root->right,res);
    res=max(res,lsum+rsum+root->data);
    return lsum+rsum+root->data;
}

int findLargestSubtreeSum(Node* root){
    if(!root){
        return 0;
    }
    int res=INT_MIN;
    solve(root,res);
    return res;
}

int main(){
    Node* root = newNode(1); 
    root->left = newNode(-2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(-6); 
    root->right->right = newNode(2); 
    cout << findLargestSubtreeSum(root);
}