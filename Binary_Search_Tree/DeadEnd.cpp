#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node 
{ 
    int key; 
    struct Node *left, *right; 
}; 
  
Node * newNode(int k) 
{ 
    Node *temp = new Node; 
    temp->key = k; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

bool deadEnd(Node* root,int mini,int maxi){
    if(!root){
        return false;
    }
    if(mini==maxi){
        return true;
    }
    bool left = deadEnd(root->left,mini,root->key-1);
    bool right = deadEnd(root->right,root->key+1,maxi);
    return left||right;
}

struct Node* insert(struct Node* node, int key) 
{ 
    /* If the tree is empty, return a new Node */
    if (node == NULL) 
        return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
  
    /* return the (unchanged) Node pointer */
    return node; 
} 

int main(){
    Node* root = NULL; 
    root = insert(root, 8); 
    root = insert(root, 5); 
    root = insert(root, 2); 
    root = insert(root, 3); 
    root = insert(root, 7); 
    root = insert(root, 11); 
    root = insert(root, 4); 
    if (deadEnd(root,1,INT_MAX) == true) 
        cout << "Yes " << endl; 
    else
        cout << "No " << endl; 
    return 0; 
}