//https://practice.geeksforgeeks.org/problems/construct-tree-1/

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

int search(int in[],int s,int e,int val){
    for(int i=s;i<=e;i++){
        if(in[i]==val){
            return i;
        }
    }
}

Node* solve(int in[],int pre[],int s,int e,int &index){
    if(e<s){
        return NULL;
    }
    Node* root = new Node(pre[index]);
    int pos = search(in,s,e,pre[index]);
    index++;
    root->left = solve(in,pre,s,pos-1,index);
    root->right = solve(in,pre,pos+1,e,index);
    return root;
}

Node* buildTree(int in[],int pre[], int n)
{
    int start=0;
    return solve(in,pre,0,n-1,start);
}