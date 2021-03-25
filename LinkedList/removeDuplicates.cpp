//https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1

#include<bits/stdc++.h> 
using namespace std; 


struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

Node *removeDuplicates(Node *root)
{
 if(!root){
     return root;
 }
 Node* curr = root;
 while(curr->next){
     if(curr->data == curr->next->data){
         curr->next = curr->next->next;
     }
     else{
        curr=curr->next;
     }
 }
 return root;
}