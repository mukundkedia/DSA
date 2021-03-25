//https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#


struct Node{
  int data;
  struct Node* next;
};

 void removeLoop(Node* head)
    {
       Node* slow = head;
       Node* fast = head;
       while(slow and fast and fast->next){
           slow=slow->next;
           fast = fast->next->next;
           if(slow==fast){
               break;
           }
       }
    
    if(slow==fast){
        
        Node* slow = head;
        
        if(slow==fast){
            while(fast->next!=slow){
                fast=fast->next;
            }
        }
        else{
             while(slow->next!=fast->next){
            slow=slow->next;
            fast=fast->next;
        }
        }
        fast->next = NULL;
    }
    }