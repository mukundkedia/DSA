//https://www.geeksforgeeks.org/print-common-nodes-path-root-common-ancestors/
//PC
//TBW

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

bool print(Node* root,int target){
    if(!root){
        return false;
    }
    if(root->key == target){
        cout<<root->key<<" ";
        return true;
    }
    if(print(root->left,target) || print(root->right,target)){
        cout<<root->key<<" ";
        return true;
    }
    return false;
}

void path(Node* root,int a,int b){
    Node* lca = findLCA(root,a,b);
    print(root,lca->key);
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
    path(root, 4, 5); 
    cout<<"\n";
    path(root, 4, 6); 
    cout<<"\n";
    path(root, 3, 4); 
    cout<<"\n";
    path(root, 2, 4); 
    return 0;
}