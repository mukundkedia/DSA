#include <bits/stdc++.h> 
using namespace std; 
  
/* https://www.geeksforgeeks.org/double-tree/ */
/* PC */


/* A binary tree node has data,  
pointer to left child and a  
pointer to right child */
class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
};  
  
/* function to create a new  
node of tree and returns pointer */
node* newNode(int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
      
    return(Node);  
} 

void doubleTree(node*  root){
    if(!root){
        return;
    }
    doubleTree(root->left);
    node* temp = root->left;
    root->left = newNode(root->data);
    root->left->left = temp;
    doubleTree(root->right);
}

void printInorder(node* node)  
{  
    if (node == NULL)  
        return;  
    printInorder(node->left);  
    cout << node->data << " ";  
    printInorder(node->right);  
}  

int main()  
{  
      
    /* Constructed binary tree is  
                1  
            / \  
            2 3  
        / \  
        4 5  
    */
    node *root = newNode(1);  
    root->left = newNode(2);  
    root->right = newNode(3);  
    root->left->left = newNode(4);  
    root->left->right = newNode(5);  
      
    cout << "Inorder traversal of the original tree is \n";  
    printInorder(root);  
      
    doubleTree(root);  
          
    cout << "\nInorder traversal of the double tree is \n";  
    printInorder(root);  
      
    return 0;  
}  