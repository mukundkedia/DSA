//https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  Node* next;
  Node* bottom;
  Node(int data){
    next=NULL;
    bottom=NULL;
    data=data;
  }
};

Node* merge(Node* a,Node* b){
    Node* res;
    if(a==NULL){
        return b;
    }
    if(!b){
        return a;
    }
    if(a->data<b->data){
        res=a;
        res->bottom=merge(a->bottom,b);
    }
    else{
        res=b;
        res->bottom=merge(a,b->bottom);
    }
    res->next=NULL;
    return res;
}
/*  Function which returns the  root of 
    the flattened linked list. */
Node *flatten(Node *root)
{
   if(root==NULL || root->next==NULL){
       return root;
   }
   return merge(root,flatten(root->next));
}