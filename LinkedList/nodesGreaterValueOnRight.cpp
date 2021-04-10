//https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1#

Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    Node *compute(Node *head)
    {
        Node* newHead = reverse(head);
        int maxVal = newHead->data;
        Node* curr = newHead->next;
        Node* temp = newHead;
        Node* ans=temp;
        while(curr){
            if(curr->data>=maxVal){
                temp->next = curr;
                temp = temp->next;
            }
            if(!curr->next){
                temp->next = NULL;
            }
            maxVal = max(maxVal,curr->data);
            curr=curr->next;
        }
       
        return reverse(ans);
    }