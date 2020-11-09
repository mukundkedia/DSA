//https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1

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

vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
  queue<Node*> q;
  q.push(root);
  while(!q.empty()){
      Node* temp = q.front();
      q.pop();
      ans.push_back(temp->data);
      if(temp->right){
          q.push(temp->right);
      }
      if(temp->left){
          q.push(temp->left);
      }
  }
  reverse(ans.begin(),ans.end());
  return ans;
}