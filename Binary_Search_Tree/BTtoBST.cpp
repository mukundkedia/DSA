//https://www.geeksforgeeks.org/binary-tree-to-binary-search-tree-conversion/
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

void store(Node* root,vector<int>& temp){
    if(!root){
        return;
    }
    temp.push_back(root->key);
    store(root->left,temp);
    store(root->right,temp);
}

void solve(Node* root,vector<int> temp,int &index,int n){
    if(index>=n){
        return;
    }
    if(!root){
        return;
    }
    solve(root->left,temp,index,n);
    root->key = temp[index++];
    solve(root->right,temp,index,n);
}

int main(){
    struct Node* root = NULL; 
  
    /* Constructing tree given in the above figure 
          10 
         /  \ 
        30   15 
       /      \ 
      20       5   */
    root = newNode(10); 
    root->left = newNode(30); 
    root->right = newNode(15); 
    root->left->left = newNode(20); 
    root->right->right = newNode(5); 
    printInorder(root);
    cout<<"\n";
  	vector<int> temp;
    store(root,temp);
    sort(temp.begin(),temp.end());
    int n = temp.size();
    int index=0;
    solve(root,temp,index,n);
    printInorder(root);
}