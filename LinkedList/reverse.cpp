//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

#include<bits/stdc++.h>
using namespace std;

struct Node* reverseList(struct Node *head)
{
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* nxt=NULL;
    while(curr!=NULL){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    head = prev;
    return head;
}

//recursive

struct Node* reverseList(struct Node *head)
{
    if(head==NULL || head->next==NULL){
        return head;
    }
    struct Node* rest = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return rest;
}
