//https://practice.geeksforgeeks.org/problems/binary-tree-to-dll/

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

void solve(Node* root,Node* &head,Node* &tail){
    if(!root){
        return;
    }
    solve(root->left,head,tail);
    if(!head){
        head = root;
        tail = root;
    }
    else{
        tail->right = root;
        root->left = tail;
        tail = root;
    }
    solve(root->right,head,tail);
    
}


Node * bToDLL(Node *root)
{
    Node* head=NULL;
    Node* tail = NULL;
    
    solve(root,head,tail);
    return head;
}