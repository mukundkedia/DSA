//https://practice.geeksforgeeks.org/problems/add-two-numbers-represented-by-linked-lists/1#

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

    Node* reverse(Node* &head){
        Node* prev = NULL;
        Node* curr = head;
        Node* nxt = NULL;
        while(curr!=NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        head = prev;
        return head;
    }
    
    
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node* frev = reverse(first);
        Node* srev = reverse(second);
        Node* res = NULL;
        Node* curr=NULL;
        Node* temp;
        int carry = 0;
        while( frev || srev){
            int sum = carry;
            if(frev){
                sum+=frev->data;
                frev=frev->next;
            }
            if(srev){
                sum+=srev->data;
                srev=srev->next;
            }
            carry = sum/10;
            sum=sum%10;
            temp = new Node(sum);
            if(res==NULL){
                res=temp;
            }
            else{
                curr->next=temp;
            }
                curr=temp;
        }
        if(carry>0){
            temp->next = new Node(carry);
        }
        
        return reverse(res);
    }