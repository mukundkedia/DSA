// https://www.geeksforgeeks.org/lowest-common-ancestor-binary-tree-set-1/
// PC
// TBW

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

Node* findLCA(Node* root,int a,int b){
    if(!root){
        return NULL;
    }
    if(root->key==a || root->key==b){
        return root;
    }
    Node* l = findLCA(root->left,a,b);
    Node* r = findLCA(root->right,a,b);
    if(l and r){
        return root;
    }
    if(l){
        return l;
    }
    if(r){
        return r;
    }
}

int main()
{
Node * root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(6); 
    root->right->right = newNode(7); 
    cout << "LCA(4, 5) = " << findLCA(root, 4, 5)->key<<" "; 
    cout << "LCA(4, 6) = " << findLCA(root, 4, 6)->key<<" "; 
    cout << "LCA(3, 4) = " << findLCA(root, 3, 4)->key<<" "; 
    cout << "LCA(2, 4) = " << findLCA(root, 2, 4)->key<<" "; 
    return 0;
}