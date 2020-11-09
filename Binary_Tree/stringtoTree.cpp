//https://www.geeksforgeeks.org/construct-binary-tree-string-bracket-representation/

#include<bits/stdc++.h> 
using namespace std; 
  
struct Node 
{ 
    int data; 
    Node *left, *right; 
}; 
  
int start=0;
//New node of a tree 
Node *newNode(int data) 
{ 
    Node *node = new Node; 
    node->data = data; 
    node->left = node->right = NULL; 
    return node; 
} 

Node* strtoTree(string s){
    if(start>s.size()){
        return NULL;
    }
    bool neg = false;
    if(s[start]=='-'){
        neg=true;
        start++;
    }
    int num=0;
    while(start<s.size() and (s[start]>='0' and s[start]<='9')){
        int digit = s[start]-'0';
        num=num*10+ digit;
        start++;
    }
    if(neg){
        num=-num;
    }
    Node* root = newNode(num);
    if(start>=s.size()){
        return root;
    }
    if(start<s.size() and s[start]=='('){
        start++;
        root->left = strtoTree(s);
    }
    if(start<s.size() and s[start]==')'){
        start++;
        return root;
    }
    if(start<s.size() and s[start]=='('){
        start++;
        root->right = strtoTree(s);
    }
    if(start<s.size() and s[start]==')'){
        start++;
        return root;
    }
    return root;
}

void preOrder(Node* node)
{
    if (node == NULL)
        return;
    preOrder(node->left);
    cout<<node->data<<" ";
    preOrder(node->right);
}

Node* solve(string s){
    int len = s.size();
    if(len==0){
        return NULL;
    }
    return strtoTree(s);
}

int main(){
    string s;
    cin>>s;
    Node* ans = solve(s);
    preOrder(ans);
}