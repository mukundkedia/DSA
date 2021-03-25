//https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1

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


Node * removeDuplicates( Node *head) 
    {
        unordered_set<int> set1;
     Node* curr = head;
     Node* prev = NULL;
     while(curr!=NULL){
         if(set1.find(curr->data)!=set1.end()){
             prev->next = curr->next;
             delete(curr);
         }
         else{
             set1.insert(curr->data);
             prev = curr;
         }
         curr=prev->next;
     }
      return head;
    }