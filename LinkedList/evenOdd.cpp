//https://practice.geeksforgeeks.org/problems/segregate-even-and-odd-nodes-in-a-linked-list5035/1#

Node* divide(int N, Node *head){
        Node* curr=head;
        Node *evenst=NULL,*evenend=NULL,*oddst=NULL,*oddend=NULL;
        while(curr){
            int val=curr->data;
            if(val%2){
                if(!oddst){
                    oddst=curr;
                    oddend=curr;
                }
                else{
                    oddend->next=curr;
                    oddend=oddend->next;
                }
            }
            else{
                if(!evenst){
                    evenst=curr;
                    evenend=curr;
                }
                else{
                    evenend->next=curr;
                    evenend=evenend->next;
                }
            }
            curr=curr->next;
        }
        if(!evenst || !oddst){
            return head;
        }
        evenend->next=oddst;
        oddend->next=NULL;
        return evenst;
    }