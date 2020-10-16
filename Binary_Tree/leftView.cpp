// https://www.geeksforgeeks.org/print-left-view-binary-tree/
// PC

#include <bits/stdc++.h> 
using namespace std; 
  
class node{ 
public: 
    int data; 
    node *left, *right; 
}; 
  
// A utility function to create a new Binary Tree node 
node* newNode(int item) 
{ 
    node* temp = new node(); 
    temp->data = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}

void solve(vector<int>& vec,int depth,node* root){
    if(root==NULL){
        return;
    }
    if(depth>=vec.size()){
        cout<<root->data<<" ";
        vec.push_back(root->data);
    }
    solve(vec,depth+1,root->left);
    solve(vec,depth+1,root->right);
}


void leftView(node *root)
{
  vector<int> ans;
  solve(ans,0,root);
 
}

int main() 
{ 
    node* root = newNode(12); 
    root->left = newNode(10); 
    root->right = newNode(30); 
    root->right->left = newNode(25); 
    root->right->right = newNode(40); 
  
    leftView(root); 
  
    return 0; 
} 