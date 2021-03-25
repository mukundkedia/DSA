//https://practice.geeksforgeeks.org/problems/add-1-to-a-number-represented-as-linked-list/1

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* next;
    Node(int x){
      data=x;
      next = NULL;
    }
};

Node* addOne(Node *head) 
    {
       Node* prev = NULL;
       Node* curr = head;
       Node* nxt  = NULL;
       while(curr!=NULL){
           nxt = curr->next;
           curr->next = prev;
           prev = curr;
           curr = nxt;
       }
       head = prev;
       Node* temp = head;
       temp->data+=1;
       while(temp!=NULL){
           if(temp->data!=10){
               break;
           }
           else{
               temp->data=0;
               if(temp->next){
                   temp->next->data+=1;
                   temp=temp->next;
               }
               else{
                   temp->next = new Node(1);
                   break;
               }
           }
       }
      prev = NULL;
      curr = head;
      nxt  = NULL;
       while(curr!=NULL){
           nxt = curr->next;
           curr->next = prev;
           prev = curr;
           curr = nxt;
       }
       head = prev;
       return head;
    }