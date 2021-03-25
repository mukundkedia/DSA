//https://practice.geeksforgeeks.org/problems/intersection-point-in-y-shapped-linked-lists/1

struct Node{
  int data;
  Node* next;
  Node(int x){
    data=x;
    next=NULL;
  }
}


#include<bits/stdc++.h>
using namespace std;

int len(Node* temp){
    int ans=0;
    while(temp){
        ans++;
        temp=temp->next;
    }
    return ans;
}   
   
int intersectPoint(Node* head1, Node* head2)
{
    Node* t1 = head1;
    Node* t2 = head2;
    int l1 = len(t1);
    int l2 = len(t2);
    if(l1>l2){
        int data = l1-l2;
        while(data--){
            head1 = head1->next;
        }
    }
    else{
         int data = l2-l1;
        while(data--){
            head2 = head2->next;
        }
    }
    while(head1 and head2){
        if(head1==head2){
            return head1->data;
        }
        head1=head1->next;
        head2=head2->next;
    }
    return -1;
}

int intersection(Node* head1,Node* head2){
    Node* t1 = head1;
    Node* t2 = head2;
    while(t1!=t2){
        t1=t1?t1->next:head2;
        t2=t2?t2->next:head1;
    }
    return t1;
}