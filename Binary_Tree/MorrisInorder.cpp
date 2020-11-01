//https://www.youtube.com/watch?v=AHRRIZWKGPY
//PC

#include <bits/stdc++.h>
#include <iostream>
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

void MorrisTraversal(Node* root){
    Node* curr = root;
    while(curr!=NULL){
        if(!curr->left){
            cout<<curr->key<<" ";
            curr=curr->right;
        }
        else{
            Node* prev = curr->left;
            while(prev->right!=NULL and prev->right!=curr){
                prev= prev->right;
            }
            if(prev->right==NULL){
                prev->right = curr;
                curr=curr->left;
            }
            else{
                cout<<curr->key<<" ";
                prev->right=NULL;
                curr=curr->right;
            }
        }
    }
}

int main() 
{ 
  
    /* Constructed binary tree is 
            1 
          /   \ 
         2     3 
       /   \ 
      4     5 
  */
    struct Node* root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
  
    MorrisTraversal(root); 
  
    return 0; 
} 