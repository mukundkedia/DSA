//https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}; 
  
// Utility function creates a new binary tree node with given key 
Node * newNode(int k) 
{ 
    Node *temp = new Node; 
    temp->data = k; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

Node* insert(Node* root, int Key)
{
    if(!root){
        root = new Node(Key);
        return root;
    }
    if(root->data==Key){
        return root;
    }
    if(root->data>Key){
        root->left = insert(root->left,Key);
    }
    else{
        root->right = insert(root->right,Key);
    }
    return root;
}