//https://practice.geeksforgeeks.org/problems/populate-inorder-successor-for-all-nodes/1

void inorder(struct node* root,struct node* &next){
    if(!root){
        return;
    }
    inorder(root->right,next);
    root->next=next;
    next=root;
    inorder(root->left,next);
}

void populateNext(struct node* p)
{
    if(!p){
        return;
    }
    struct node* next=NULL;
  inorder(p,next);
}