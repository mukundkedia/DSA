//

void inorder(Node* root,vector<int>& vec){
    if(!root){
        return;
    }
    inorder(root->left,vec);
    vec.push_back(root->data);
    inorder(root->right,vec);
}

int countPairs(Node* root1, Node* root2, int x)
{
    int count=0;
    vector<int> a,b;
    inorder(root1,a);
    inorder(root2,b);
    int s=0,e=b.size()-1;
    while(s<a.size() and e>=0){
        if(a[s]+b[e]==x){
            count++;
            s++;
            e--;
        }
        else if(a[s]+b[e]<x){
            s++;
        }
        else{
            e--;
        }
    }
    return count;
}