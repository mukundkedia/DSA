//https://practice.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1#

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


Node* findIntersection(Node* head1, Node* head2)
{
    Node* res=NULL;
    Node* temp;
    Node* curr=NULL;
    Node* h1=head1;
    Node* h2=head2;
    while(h1 and h2){
        if(h1->data == h2->data){
            temp = new Node(h1->data);
            if(res==NULL){
                res=temp;
            }
            else{
                curr->next = temp;
            }
            curr = temp;
            h1=h1->next;
            h2=h2->next;
        }
        else if(h1->data<h2->data){
            h1=h1->next;
        }
        else{
            h2=h2->next;
        }
    }
    return res;
}