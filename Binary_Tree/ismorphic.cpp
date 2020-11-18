//https://practice.geeksforgeeks.org/problems/check-if-tree-is-isomorphic

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

bool isIsomorphic(Node *root1,Node *root2)
{
if(root1==NULL and root2==NULL){
    return true;
}
if(root1==NULL || root2==NULL){
    return false;
}
if(root1->key!=root2->key){
    return false;
}
if((isIsomorphic(root1->left,root2->right) and isIsomorphic(root1->right,root2->left))||
    (isIsomorphic(root1->left,root2->left) and isIsomorphic(root1->right,root2->right))
){
    return true;
}
else{
    return false;
}
}