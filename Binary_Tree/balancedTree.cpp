//https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

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


int solve(Node* root,bool &ans){
    if(!root){
        return 0;
    }
    int l = solve(root->left,ans);
    int r = solve(root->right,ans);
    if(abs(l-r)>1){
        ans=false;
    }
    return max(l,r)+1;
}

// is balanced, else false. 
bool isBalanced(Node *root)
{
    bool ans=true;
    solve(root,ans);
    return ans;
}