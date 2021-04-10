//https://practice.geeksforgeeks.org/problems/quick-sort-on-linked-list/1


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

struct node * partition(struct node *head, struct node *tail){
node * prev=head, *cur=head->next;
node *pivot = head;
while(cur != tail->next){
if(cur->data < pivot->data){
swap(prev->next->data,cur->data);
prev = prev->next;
}
cur = cur->next;
}
swap(pivot->data,prev->data);
return prev;
}

void quickSortRec(struct node*& head,struct node* tail){
    if(head==tail || head==NULL || tail==NULL){
        return;
    }
    
    struct node* pivot = partition(head, tail);
    quickSortRec(head,pivot);
    quickSortRec(pivot->next,tail);
}
//you have to complete this function
void quickSort(struct node **headRef) {
    struct node* tail = *headRef;
    while(tail->next){
        tail=tail->next;
    }
    quickSortRec(*headRef,tail);
}