//

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

Node* reverse(Node* head){
        Node* curr=head;
        Node* prev=NULL;
        Node* next=NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr=next;
        }
        return prev;
    }

bool isPalindrome(Node *head)
    {
        Node* prev = head;
        Node* slow = head;
        Node* fast = head;
        if(!head->next){
            return 1;
        }
        if(head->next->next==NULL){
            return head->data==head->next->data;
        }
        while(fast and fast->next){
            prev=slow;
          slow=slow->next;
          fast=fast->next->next;
          }
          prev->next=NULL;
        Node* head2 = reverse(slow);
        int ans=1;
        while(head2 and head){
            if(head->data==head2->data){
                head=head->next;
                head2=head2->next;
            }
            else{
                ans=0;
                break;
            }
        }
        return ans;
    }