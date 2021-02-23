//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1

struct node *reverse (struct node *head, int k)
{ 
    struct node* curr = head;
    struct node* prev = NULL;
    struct node* next = NULL;
    int count=0;
    while(curr!=NULL and count<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(next){
        head->next = reverse(curr,k);
    }
    return prev;
}
