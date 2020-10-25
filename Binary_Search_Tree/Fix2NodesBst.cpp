//https://leetcode.com/problems/recover-binary-search-tree/
//PC

void solve(Node* root,Node* &first,Node* &second,Node* &prev){
        if(!root){
            return;
        }
        solve(root->left,first,second,prev);
         if(prev && prev->data > root->data){
            if(!first){
                first = prev;
                second = root;
            }
            else{
                second = root;
            }
         }
        
        prev=root;
        solve(root->right,first,second,prev);
    }


struct Node *correctBST( struct Node* root )
{
   
        Node* first = NULL;
       Node* second = NULL;
        Node* prev = NULL;
        
        solve(root,first,second,prev);

        swap(first->data,second->data);
      
        return root;
}
