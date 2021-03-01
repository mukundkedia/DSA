//https://practice.geeksforgeeks.org/problems/largest-bst/1#
//KM
#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* left;
  Node* right;
};

struct Bst{
    bool isBST;
    int size;
    int min;
    int max;
};

struct Bst solve(Node* root){
    if(!root){
        Bst b = {1,0,INT_MAX,INT_MIN};
        return b;
    }
    Bst l = solve(root->left);
    Bst r = solve(root->right);
    
    if(l.isBST and r.isBST and root->data>l.max and root->data<r.min){
        Bst b = {1,l.size+r.size+1,min(root->data,l.min),max(root->data,r.max)};
        return b;
    }
    Bst b = {0,max(l.size,r.size),-1,-1};
    return b;
}

int largestBst(Node *root)
{
	Bst res = solve(root);
	return res.size;
}