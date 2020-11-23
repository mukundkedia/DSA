//https://practice.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}; 
  
Node * newNode(int k) 
{ 
    Node *temp = new Node; 
    temp->data = k; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

Node* LCA(Node *root, int n1, int n2)
{
    if(!root){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
   else if(n1<root->data and n2>root->data){
       return root;
   }
   else if(n1>root->data and n2<root->data){
       return root;
   }
   else if(n1>root->data and n2>root->data){
       return LCA(root->right,n1,n2);
   }
   else if(n1<root->data and n2<root->data){
       return LCA(root->left,n1,n2);
   }
}