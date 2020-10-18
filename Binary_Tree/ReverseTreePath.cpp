// PC
// TBW
// https://www.geeksforgeeks.org/reverse-tree-path/

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

Node* reverse(Node* root,map<int,int> map1,int level,int &pos,int val){
    if(!root){
        return NULL;
    }
    if(root->key == val){
        map1[level] = root->key;
        root->key = map1[pos];
        pos++;
        return root;
    }
    map1[level] = root->key;
    Node *left, *right; 
    left = reverse(root->left, map1,level + 1, pos,val); 
    if (left == NULL) 
        right = reverse(root->right,map1,level + 1, pos,val); 
    if(left || right){
        root->key = map1[pos];
        pos++;
       return (left ? left : right); 
    }
    return NULL;
}

void reverseTreePath(Node* root,int val){
    map<int,int> map1;
    int level=0;
    int pos=0;
    reverse(root,map1,level,pos,val);
}

void inorder(Node* root) 
{ 
    if (root != NULL) { 
        inorder(root->left); 
        cout << root->key << " "; 
        inorder(root->right); 
    } 
} 

int main() 
{ 
    // Let us create binary tree shown in above diagram 
    Node* root = newNode(7); 
    root->left = newNode(6); 
    root->right = newNode(5); 
    root->left->left = newNode(4); 
    root->left->right = newNode(3); 
    root->right->left = newNode(2); 
    root->right->right = newNode(1); 
  
    /*     7 
         /    \ 
        6       5 
       / \     / \ 
      4  3     2  1          */
  
    int data = 4; 
  
    // Reverse Tree Path 
    reverseTreePath(root, data); 
  
    // Traverse inorder 
    inorder(root); 
    return 0; 
} 