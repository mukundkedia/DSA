#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

int height(struct Node* node){
        if(!node){
            return 0;
        }
        int l = height(node->left);
        int r = height(node->right);
        return max(l,r)+1;
    }

Node* newNode(int data){
    Node* temp = new Node;
    temp->data=data;
    temp->left = temp->right = NULL;
    return temp;
}