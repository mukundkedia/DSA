//https://practice.geeksforgeeks.org/problems/predecessor-and-successor

#include <bits/stdc++.h>

using namespace std;
struct Node 
{ 
    int key; 
    struct Node *left, *right; 
}; 
  
// Utility function creates a new binary tree node with given key 
Node * newNode(int k) 
{ 
    Node *temp = new Node; 
    temp->key = k; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    while(root!=NULL){
        if(root->key==key){
            if(root->right){
                Node* temp = root->right;
                while(temp->left){
                    temp=temp->left;
                }
                suc=temp;
            }
            if(root->left){
                Node* temp = root->left;
                while(temp->right){
                    temp=temp->right;
                }
                pre=temp;
            }
            break;
        }
        else if(root->key>key){
            suc=root;
            root=root->left;
        }
        else{
            pre=root;
            root=root->right;
        }
    }
}