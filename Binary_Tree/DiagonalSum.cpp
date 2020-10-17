// https://www.geeksforgeeks.org/diagonal-sum-binary-tree/
// PC

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

void solve(Node* root,int level,map<int,int> &map1){
    if(!root){
        return;
    }
    map1[level]+=root->data;
    solve(root->left,level+1,map1);
    solve(root->right,level,map1);
}

void diagonalSum(Node* root){
    map<int,int> map1;
    solve(root,0,map1);
    for(auto it:map1){
        cout<<it.second<<" ";
    }
}

int main()
{
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(9);
    root->left->right = newNode(6);
    root->right->left = newNode(4);
    root->right->right = newNode(5);
    root->right->left->right = newNode(7);
    root->right->left->left = newNode(12);
    root->left->right->left = newNode(11);
    root->left->left->right = newNode(10);
 
    diagonalSum(root);
 
    return 0;
}