//https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data){
    Node* temp = new Node;
    temp->data=data;
    temp->left = temp->right = NULL;
    return temp;
}

int solve(Node* root){
    if(!root){
        return 0;
    }
    if(!root->left and !root->right){
        int val = root->data;
        root->data=0;
        return val;
        }
        int lsum = solve(root->left);
        int rsum = solve(root->right);
        int val = root->data;
        root->data = lsum+rsum;
        return lsum+rsum+val;
}


void toSumTree(Node *node)
{
    solve(node);
}