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

int findDist(Node* root,int a,int level){
    if(!root){
        return -1;
    }
    if(root->key==a){
        return level;
    }
    int l = findDist(root->left,a,level+1);
    if(l==-1){
        return findDist(root->right,a,level+1);
    }
    return l;
}

int dis(Node* root,int a,int b){
    Node* lca = findLCA(root,a,b);
    int d1 = findDist(lca,a,0);
    int d2 = findDist(lca,b,0);
    return d1+d2;
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
    cout << "LCA(4, 5) = " << dis(root, 4, 5)<<" "; 
    cout << "LCA(4, 6) = " << dis(root, 4, 6)<<" "; 
    cout << "LCA(3, 4) = " << dis(root, 3, 4)<<" "; 
    cout << "LCA(2, 4) = " << dis(root, 2, 4)<<" "; 
    return 0;
}