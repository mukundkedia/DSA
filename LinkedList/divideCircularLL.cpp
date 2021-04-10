//https://practice.geeksforgeeks.org/problems/split-a-circular-linked-list-into-two-halves/1

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

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
   Node* st = head;
   Node* slow = head;
   Node* fast = head;
   while(fast->next!=st){
       fast=fast->next;
       if(fast->next!=st){
            slow=slow->next;
            fast=fast->next;
       }
   }
   *head2_ref = slow->next;
   fast->next = slow->next;
   slow->next = head;
   *head1_ref = head;
   
}