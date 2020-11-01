#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node 
{ 
    int key; 
    struct Node *left, *right, *parent; 
}; 
  
// Utility function creates a new binary tree node with given key 
Node * newNode(int k) 
{ 
    Node *temp = new Node; 
    temp->key = k; 
    temp->left = temp->right = temp->parent = NULL; 
    return temp; 
}

Node* insert(Node* root,int key){
    if(!root){
        return newNode(key);
    }
    if(key<root->key){
         Node* lchild = insert(root->left,key);
         root->left = lchild;
         lchild->parent = root;
    }
    else if(key>root->key){
        Node* rchild = insert(root->right,key);
         root->right = rchild;
         rchild->parent = root;
    }
    return root;
}

void inorder(struct Node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("Node : %d, ", root->key); 
        if (root->parent == NULL) 
          printf("Parent : NULL \n"); 
        else
          printf("Parent : %d \n", root->parent->key); 
        inorder(root->right); 
    } 
} 

int main(){
     Node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 
  
    // print iNoder traversal of the BST 
    inorder(root); 
}