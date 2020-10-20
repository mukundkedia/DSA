int solve(Node* root,int &ans){
    if(!root){
        return 0;
    }
    if(!root->left and !root->right){
        return root->data;
    }
    int l=solve(root->left,ans);
    int r=solve(root->right,ans);
    
    if(root->left and root->right){
        ans=max(ans,l+r+root->data);
        return max(l,r)+root->data;
    }
   return root->data+(!root->right?l:r);
}

int maxPathSum(Node* root)
{ 
    if(!root){
        return 0;
    }
    int ans=INT_MIN;
    solve(root,ans);
    return ans;
}