#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data){
    Node* temp = new Node;
    temp->data=data;
    temp->left = temp->right = NULL;
    return temp;
}

unordered_map<Node*,int> cnt;

void traversal_trick(Node* root){
    stack<Node*> st;
    st.push(root);
    while(!st.empty()){
        Node* curr = st.top();
        if(curr==NULL){
            st.pop();
            continue;
        }
        if(cnt[curr]==0){
            st.push(curr->left);
        }
        else if(cnt[curr]==1){
            cout<<curr->data<<" ";
        }
        else if(cnt[curr]==2){
            st.push(curr->right);
        }
        else{
            st.pop();
        }
        cnt[curr]++;
    }
}

int main()
{
	 Node *root = newNode(7); 
    Node *t = root;
    root->left = newNode(3); root->right = newNode(10);
    root->left->left = newNode(2); root->left->right = newNode(5);
    root->left->left->left = newNode(1);
    root->right->left = newNode(8); 
    root->right->right = newNode(12);
    traversal_trick(root);
}