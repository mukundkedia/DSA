//https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/
//PC

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

Node* constructTree(int pre[],int n,int &index,int mini,int maxi){
    if(index>=n){
        return NULL;
    }
    if(pre[index]<mini || pre[index]>maxi){
        return NULL;
    }
    Node* root = newNode(pre[index]);
    index++;
    root->left = constructTree(pre,n,index,mini,root->key);
    root->right = constructTree(pre,n,index,root->key,maxi);
    return root;
}

void printInorder(Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->key << " ";
    printInorder(node->right);
}

int main(){
     int pre[] = { 10, 5, 1, 7, 40, 50 };
    int size = sizeof(pre) / sizeof(pre[0]);
 	int index=0;
    Node* root = constructTree(pre,size,index,INT_MIN,INT_MAX);
    printInorder(root);
}