// https://www.geeksforgeeks.org/tilt-binary-tree/
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

int solve(Node* root,int &ans){
    if(!root){
        return 0;
    }
   int lsum = solve(root->left,ans);
    int rsum = solve(root->right,ans);
   int temp = abs(lsum-rsum);
    ans+=temp;
    return lsum+rsum+root->data;
}
int Tilt(Node* root){
    if(!root){
        return 0;
    }
    int sum=0;
     solve(root,sum);
    return sum;
}

int main() 
{ 
    /* Let us construct a Binary Tree 
        4 
       / \ 
      2   9 
     / \   \ 
    3   5   7 */
  
    Node* root = NULL; 
    root = newNode(4); 
    root->left = newNode(2); 
    root->right = newNode(9); 
    root->left->left = newNode(3); 
    root->left->right = newNode(8); 
    root->right->right = newNode(7); 
    cout <<Tilt(root); 
    return 0; 
} 