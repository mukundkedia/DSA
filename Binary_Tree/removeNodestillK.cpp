// https://www.geeksforgeeks.org/remove-nodes-root-leaf-paths-length-k/
// PC
// https://sapphireengine.com/@/o3c63r

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

Node* solve(Node* root,int level,int k){
    if(!root){
        return NULL;
    }
    root->left = solve(root->left,level+1,k);
    if(!root->left and !root->right){
        if(level<k){
            return NULL;
        }
        return root;
    }
    root->right = solve(root->right,level+1,k);
    return root;
}

Node* removeShortPathNodes(Node* root,int k){
    if(!root){
        return NULL;
    }
    int level=1;
    return solve(root,level,k);
}

void printInorder(Node *root) 
{ 
    if (root) 
    { 
        printInorder(root->left); 
        cout << root->data << " "; 
        printInorder(root->right); 
    } 
} 

int main() 
{ 
    int k = 4; 
    Node *root = newNode(1); 
    root->left = newNode(2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->left->left->left = newNode(7); 
    root->right->right = newNode(6); 
    root->right->right->left = newNode(8); 
    cout << "Inorder Traversal of Original tree" << endl; 
    printInorder(root); 
    cout << endl; 
    cout << "Inorder Traversal of Modified tree" << endl; 
    Node *res = removeShortPathNodes(root, k); 
    printInorder(res); 
    return 0; 
} 