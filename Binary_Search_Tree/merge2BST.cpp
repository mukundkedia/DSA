//https://www.geeksforgeeks.org/merge-two-balanced-binary-search-trees/
//PC

#include <bits/stdc++.h>
#include <iostream>
using namespace std;
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
  
// Utility function creates a new binary tree node with given key 
node * newNode(int k) 
{ 
    node *temp = new node; 
    temp->key = k; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

void insertInOrder(node* root,vector<int> &arr){
    if(!root){
        return;
    }
    insertInOrder(root->left,arr);
    arr.push_back(root->key);
    insertInOrder(root->right,arr);
}

void merge(vector<int> arr1,vector<int> arr2,vector<int> &temp){
    int n = arr1.size();
    int m = arr2.size();
    int i=0,j=0;
    while(i<n and j<m){
        if(arr1[i]<arr2[j]){
            temp.push_back(arr1[i]);
            i++;
        }
        else{
            temp.push_back(arr2[j]);
            j++;
        }
        }
    if(i!=n){
        while(i!=n){
            temp.push_back(arr1[i]);
            i++;
        }
    }
    else{
        while(j!=m){
            temp.push_back(arr2[j]);
            j++;
        }
    }
}

node* mergeTrees(vector<int> temp,int s,int e){
    if(s>e){
        return NULL;
    }
    int mid = (s+e+1)/2;
    node* root = newNode(temp[mid]);
    root->left = mergeTrees(temp,s,mid-1);
    root->right = mergeTrees(temp,mid+1,e);
    return root;
}

void printInorder(node* node)  
{  
    if (node == NULL)  
        return;  
  
    /* first recur on left child */
    printInorder(node->left);  
  
    cout << node->key << " ";  
  
    /* now recur on right child */
    printInorder(node->right);  
}

int main()  
{  
    /* Create following tree as first balanced BST  
        100  
        / \  
        50 300  
    / \  
    20 70  
    */
    node *root1 = newNode(100);  
    root1->left     = newNode(50);  
    root1->right = newNode(300);  
    root1->left->left = newNode(20);  
    root1->left->right = newNode(70);  
  
    /* Create following tree as second balanced BST  
            80  
        / \  
        40 120  
    */
    node *root2 = newNode(80);  
    root2->left     = newNode(40);  
    root2->right = newNode(120);  
    
    vector<int> arr1,arr2;
    insertInOrder(root1,arr1);
    insertInOrder(root2,arr2);
    
    for(int i=0;i<arr1.size();i++){
        cout<<arr1[i]<<" ";
    }
    cout<<"\n";
    for(int i=0;i<arr2.size();i++){
        cout<<arr2[i]<<" ";
    }
    cout<<"\n";
    vector<int> temp;
    
    merge(arr1,arr2,temp);
    
    for(int i=0;i<temp.size();i++){
        cout<<temp[i]<<" ";
    }
    cout<<"\n";
    
  
    node *mergedTree = mergeTrees(temp,0,temp.size()-1);  
  
    cout << "Following is Inorder traversal of the merged tree \n";  
    printInorder(mergedTree);  
  
    return 0;  
}  