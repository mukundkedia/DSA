//https://practice.geeksforgeeks.org/problems/circular-linked-list/1

#include<bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

bool isCircular(Node *head)
{
   Node* st = head;
   int flag=0;
   Node* curr=head->next;
   while(curr){
       if(st==curr){
           flag=1;
           break;
       }
       curr=curr->next;
   }
   if(flag){
       return true;
   }
   else{
       return false;
   }
}