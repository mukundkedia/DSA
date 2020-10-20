//https://www.geeksforgeeks.org/construct-bst-given-level-order-traversal/
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

Node* constructBst(vector<int> arr){
    if(arr.size()==0){
        return NULL;
    }
    Node* root = newNode(arr[0]);
   vector<int> l,r;
    for(int i=1;i<arr.size();i++){
        if(arr[i]<arr[0]){
            l.push_back(arr[i]);
        }
        else{
            r.push_back(arr[i]);
        }
    }
    arr.clear();
    root->left = constructBst(l);
    root->right = constructBst(r);
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
    vector<int>arr = {7, 4, 12, 3, 6, 8, 1, 5, 10}; 
   
    Node *root = constructBst(arr); 
      
    cout << "Inorder Traversal: "; 
    printInorder(root); 
  	
}