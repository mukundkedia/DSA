//https://www.geeksforgeeks.org/reverse-doubly-linked-list-groups-given-size/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next, *prev;
};

Node* getNode(int data){
    Node* new_node = new Node();
    new_node->data=data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

void push(Node** head,Node* new_node){
  new_node->prev = NULL;
  new_node->next = *head;
  if(*head!=NULL){
    (*head)->prev = new_node;
  }
  *head = new_node;
}

void printList(Node* head){
  while(head){
    cout<<head->data<<" ";
    head=head->next;
  }
}

Node* revListInGroupOfGivenSize(Node* head,int k){
  Node* curr=head;
  Node* next=NULL;
  Node* newhead=NULL;
  int count=0;

  while(count<k and curr){
      next=curr->next;
      push(&newhead,curr);
      curr=next;
      count++;
  }
  if(next!=NULL){
    head->next = revListInGroupOfGivenSize(next,k);
    head->next->prev = head;
  }

  return newhead;
}

int main(){
   Node* head = NULL;
    push(&head, getNode(2));
    push(&head, getNode(4));
    push(&head, getNode(8));
    push(&head, getNode(10));
      
    int k = 2;
    printList(head);
   
    // Reverse doubly linked list in groups of 
    // size 'k'
    head = revListInGroupOfGivenSize(head, k);
   
    cout << "\nModified list: ";
    printList(head);
}