//https://www.geeksforgeeks.org/check-leaves-level/
//PC

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

int solve(Node* root,bool &ans){
    if(!root){
        return 0;
    }
    int l = solve(root->left,ans);
    int r = solve(root->right,ans);
    if(root->left and root->right and l!=r){
        ans=false;
    }
    return max(l,r)+1;
}

/*You are required to complete this method*/
bool check(Node *root)
{
    bool ans=true;
    int level=0;
    if(!root){
        return true;
    }
    solve(root,ans);
    return ans;
}

int main() 
{ 
    // Let us create tree shown in third example 
    struct Node *root = newNode(12); 
    root->left = newNode(5); 
    root->left->left = newNode(3); 
    root->left->right = newNode(9); 
    root->left->left->left = newNode(1); 
    root->left->right->left = newNode(1); 
    cout<<check(root);
}
