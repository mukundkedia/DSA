// /https://leetcode.com/problems/merge-k-sorted-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    struct node{
        ListNode* curr;
        int idx;
        node(ListNode *a,int b){
            curr=a;
            idx=b;
        }
    };
    struct compare{
         bool operator()(node a,node b){
            return a.curr->val > b.curr->val;
        }
    
    };
public:
     
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        if(k==0){
            return NULL;
        }
        ListNode *head,*tail;
        head=tail=NULL;
         priority_queue<node,vector<node>,compare> heap;
         vector<ListNode*> ptr(k);
        for(int i=0;i<k;++i)
        {
            ptr[i]=lists[i];
            if(ptr[i]!=NULL)
                heap.push(node(ptr[i],i));
        }
        if(heap.empty()){
            return NULL;
        }
        head=tail=heap.top().curr;
        int idx=heap.top().idx;
        heap.pop();
        ptr[idx]=ptr[idx]->next;
        if(ptr[idx]){
            heap.push(node(ptr[idx],idx));
        }
        while(!heap.empty())
        {
            ListNode *temp=heap.top().curr;
            idx=heap.top().idx;
            heap.pop();
            
            tail->next=temp;   
            tail=tail->next;
            ptr[idx]=ptr[idx]->next;    
            if(ptr[idx]) 
                heap.push(node(ptr[idx],idx));
        }
        return head;
    }
};