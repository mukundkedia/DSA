//https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/

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

void solve(Node* root,int sum,int len,int &max_sum,int &max_len){
    if(!root){
        if(len>max_len){
            max_sum = sum;
            max_len = len;
        }
        else if(len==max_len and max_sum<sum){
            max_sum=sum;
        }
        return;
    }
    solve(root->left,sum+root->data,len+1,max_sum,max_len);
    solve(root->right,sum+root->data,len+1,max_sum,max_len);
}

int sumOfLongRootToLeafPath(Node* root)
{
    if(!root){
        return 0;
    }
    int max_sum = INT_MIN,max_len=0;
    solve(root,0,0,max_sum,max_len);
    return max_sum;
}