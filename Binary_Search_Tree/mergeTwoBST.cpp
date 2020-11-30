//https://www.geeksforgeeks.org/merge-two-balanced-binary-search-trees/

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


vector<int> merge(Node *root1, Node *root2)
{
    vector<int> res;
   stack<Node*> s1,s2;
   Node* temp=root1;
   while(temp){
       s1.push(temp);
       temp=temp->left;
   }
   temp=root2;
   while(temp){
       s2.push(temp);
       temp=temp->left;
   }
   while(s1.size()!=0 and s2.size()!=0){
       if(s1.top()->data >= s2.top()->data){
           res.push_back(s2.top()->data);
           Node* a=s2.top();
           s2.pop();
           Node* b=a->right;
            while(b){
                   s2.push(b);
                   b=b->left;
               }
           }
           else if(s1.top()->data <= s2.top()->data){
            res.push_back(s1.top()->data);
           Node* a=s1.top();
           s1.pop();
           Node* b=a->right;
            while(b){
                   s1.push(b);
                   b=b->left;
               }
           }
           
       }
       while(s1.size()!=0){
            res.push_back(s1.top()->data);
           Node* a=s1.top();
           s1.pop();
           Node* b=a->right;
            while(b){
                   s1.push(b);
                   b=b->left;
               }
       }
       while(s2.size()!=0){
           res.push_back(s2.top()->data);
           Node* a=s2.top();
           s2.pop();
           Node* b=a->right;
            while(b){
                   s2.push(b);
                   b=b->left;
               }
   }
   return res;
}