//https://leetcode.com/problems/delete-node-in-a-bst/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node 
{ 
    int val; 
    struct Node *left, *right; 
}; 
  
// Utility function creates a new binary tree node with given key 
Node * newNode(int k) 
{ 
    Node *temp = new Node; 
    temp->val = k; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

 Node* deleteNode(Node* root, int key) {
        if (root==NULL) return NULL;
        
        if (root->val == key){
            if(root->left == NULL)  return root->right;
            if(root->right == NULL) return root->left;
            if(root->right!=NULL && root->left!=NULL){
                Node *temp = root->right;
                while(temp->left!=NULL) temp = temp->left;
                root->val = temp->val;
                root->right = deleteNode(root->right,root->val);
                
            }
        }
        else{
            if (root->val>key)  root->left = deleteNode(root->left,key);
            else    root->right = deleteNode(root->right,key);
        }
        return root;
    }