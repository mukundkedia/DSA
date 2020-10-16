// https://www.geeksforgeeks.org/connect-leaves-doubly-linked-list/
// PC
// ++

#include <bits/stdc++.h> 
using namespace std; 
  
// Structure for tree and linked list  
class Node  
{  
    public: 
    int data;  
    Node *left, *right;  
};

Node* newNode(int data)  
{  
    Node* node = new Node(); 
    node->data = data;  
    node->left = node->right = NULL;  
    return node;  
}  

void printList(Node *head)  
{  
    while (head)  
    {  
        cout<<head->data<<" ";  
        head = head->right;  
    }  
} 

Node* BTtoDLL(Node* root,Node* &head, Node* &tail){
    if(!root){
        return NULL;
    }
    
    if(!root->left and !root->right){
        if(!head){
            head = root;
            }
        else{
            root->left = tail;
            tail->right = root;
        }
        tail = root;
        return NULL;
    }
    root->left = BTtoDLL(root->left,head,tail);
    root->right = BTtoDLL(root->right,head,tail);
    return root;
}

int main()  
{  
    Node *root = newNode(1);  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
    root->right->right = newNode(6);  
    root->left->left->left = newNode(7);  
    root->left->left->right = newNode(8);  
    root->right->right->left = newNode(9);  
    root->right->right->right = newNode(10);  
  
   	Node* head=NULL;
    Node* tail = NULL;
    BTtoDLL(root,head,tail);
  
    cout << "\nExtracted Double Linked list is:\n";  
    printList(head);  
  
     
   
    return 0;  
}  