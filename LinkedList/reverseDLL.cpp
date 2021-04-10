//https://practice.geeksforgeeks.org/problems/reverse-a-doubly-linked-list/1

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
    Node(int x){
      data=x;
      next = NULL;
    }
};

Node* reverseDLL(Node * head)
{
    Node* head2 = head;
    while(head2->next){
        head2 = head2->next;
    }
   Node* pre=NULL;
   Node* nex = NULL;
   Node* curr = head;
   while(curr){
       nex = curr->next;
       curr->next = pre;
       pre = curr;
       curr = nex;
   }
   
    pre=NULL;
    nex = NULL;
    curr = head2;
   while(curr){
       nex = curr->prev;
       curr->prev = pre;
       pre = curr;
       curr = nex;
   }
   return head2;
}