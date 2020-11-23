//https://www.geeksforgeeks.org/construct-bst-from-given-preorder-traversa/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct Node 
{ 
    int data; 
    struct Node *left, *right; 
}; 
  
Node * newNode(int k) 
{ 
    Node *temp = new Node; 
    temp->data = k; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

void printInorder(Node* node)
{
    if (node == NULL)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

Node* constructTree(int pre[],int size,int &index,int mini,int maxi){
    if(index>=size){
        return NULL;
    }
    if(pre[index]<mini || pre[index]>maxi){
        return NULL;
    }
    Node* root = newNode(pre[index]);
    index++;
    root->left = constructTree(pre,size,index,mini,root->data);
    root->right = constructTree(pre,size,index,root->data,maxi);
    return root;
}

int main()
{
    int pre[] = { 10, 5, 1, 7, 40, 50 };
    int size = sizeof(pre) / sizeof(pre[0]);
 	int index=0;
    Node* root = constructTree(pre, size, index,INT_MIN,INT_MAX);
 
    cout << "Inorder traversal of the constructed tree: \n";
    printInorder(root);
 
    return 0;
}