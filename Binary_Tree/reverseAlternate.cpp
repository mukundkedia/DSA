// https://www.geeksforgeeks.org/reverse-alternate-levels-binary-tree/
// PC


#include <bits/stdc++.h> 
using namespace std; 
  
// Structure for tree and linked list  
class Node  
{  
    public: 
    char data;  
    Node *left, *right;  
};

Node* newNode(int data)  
{  
    Node* node = new Node(); 
    node->data = data;  
    node->left = node->right = NULL;  
    return node;  
}  

void reverseUtil(Node* a,Node* b,int level){
    if(!a and !b){
        return;
    }
    if(level%2==0){
        swap(a->data,b->data);
    }
    reverseUtil(a->left,b->right,level+1);
    reverseUtil(a->right,b->left,level+1);
}

void reverse(Node* root){
    if(!root){
        return;
    }
    int level=0;
    reverseUtil(root->left,root->right,level);
}

void printInorder(Node* root) 
{ 
    if (root == NULL) 
       return; 
    printInorder(root->left); 
    cout << root->data << " "; 
    printInorder(root->right); 
} 

int main()  
{  
    Node *root = newNode('a'); 
    root->left = newNode('b'); 
    root->right = newNode('c'); 
    root->left->left = newNode('d'); 
    root->left->right = newNode('e'); 
    root->right->left = newNode('f'); 
    root->right->right = newNode('g'); 
    root->left->left->left = newNode('h'); 
    root->left->left->right = newNode('i'); 
    root->left->right->left = newNode('j'); 
    root->left->right->right = newNode('k'); 
    root->right->left->left = newNode('l'); 
    root->right->left->right = newNode('m'); 
    root->right->right->left = newNode('n'); 
    root->right->right->right = newNode('o'); 
  
    printInorder(root);
    cout<<"\n";
   	reverse(root);
  	printInorder(root);
}  