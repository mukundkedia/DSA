// https://www.geeksforgeeks.org/find-height-of-a-special-binary-tree-whose-leaf-nodes-are-connected/
// PC


int findTreeHeight(Node* root)
{
    if(!root){
        return 0;
    }
	if(root->left!=NULL and root == root->left->right ){
	    return 1;
	}
	int l = findTreeHeight(root->left);
	int r = findTreeHeight(root->right);
	return max(l,r)+1;
}