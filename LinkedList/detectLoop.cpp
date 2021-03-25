struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


bool detectLoop(Node* head)
{
   Node* slow = head;
   Node* fast = head;
   while(slow and fast and fast->next){
       slow=slow->next;
       fast=fast->next->next;
       if(slow==fast){
           return true;
       }
   }
   return false;
}