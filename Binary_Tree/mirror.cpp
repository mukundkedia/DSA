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

void mirror(Node* node) 
{
     if(!node){
         return;
     }
     Node* temp = node->left;
     node->left = node->right;
     node->right = temp;
     if(node->left){
         mirror(node->left);
     }
     if(node->right){
         mirror(node->right);
     }
}