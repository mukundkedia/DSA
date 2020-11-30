//https://www.geeksforgeeks.org/convert-normal-bst-balanced-bst/

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


Node* create(vector<int> vec,int l,int r){
    if(l>r){
        return NULL;
    }
    int mid = l + (r-l)/2;
    Node* root = new Node(vec[mid]);
    root->left = create(vec,l,mid-1);
    root->right = create(vec,mid+1,r);
    return root;
}

void store(Node* root,vector<int>& vec){
    if(!root){
        return;
    }
    store(root->left,vec);
    vec.push_back(root->data);
    store(root->right,vec);
}


Node* buildBalancedTree(Node* root)
{
	vector<int> vec;
	store(root,vec);
	return create(vec,0,vec.size()-1);
}