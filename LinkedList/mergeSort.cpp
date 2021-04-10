//https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1

#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  struct Node* next;
};

void divideIntoTwo(Node* headref,Node*& a,Node*& b){
    Node* slow = headref;
    Node* fast = headref->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast){
            slow=slow->next;
            fast=fast->next;
        }
    }
    a=headref;
    b=slow->next;
    slow->next=NULL;
}   

Node* mergeSorted(Node* c,Node* d){
    
    Node* res =NULL;
    if(c==NULL){
        return d;
    }
    if(d==NULL){
        return c;
    }
    if(c->data<=d->data){
        res = c;
        res->next = mergeSorted(c->next,d);
    }
    else{
        res=d;
        res->next = mergeSorted(c,d->next);
    }
    return res;
}
   
Node* mergeSort(Node* head) {
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* headRef = head;
    Node* a;
    Node* b;
    divideIntoTwo(headRef,a,b);
    Node* heada = mergeSort(a);
    Node* headb = mergeSort(b);
    return mergeSorted(heada,headb);
}