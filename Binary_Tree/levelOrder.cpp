//https://practice.geeksforgeeks.org/problems/level-order-traversal/1

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
     Node* left;
     Node* right;
    };

Node* newNode(int data) 
{ 
    Node* node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
} 

vector<int> levelOrder(Node* node)
{
  vector<int> ans;
  queue<Node*> q;
  q.push(node);
  while(!q.empty()){
      Node* temp = q.front();
      q.pop();
      ans.push_back(temp->data);
      if(temp->left){
          q.push(temp->left);
      }
      if(temp->right){
          q.push(temp->right);
      }
  }
  return ans;
}

int main(){

}