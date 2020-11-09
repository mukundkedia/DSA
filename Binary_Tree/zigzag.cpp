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

vector <int> zigZagTraversal(Node* root)
{
    vector<int> ans;    
	 stack<Node*> s1;
	 stack<Node*> s2;
	 s1.push(root);
	 while(!s1.empty() || !s2.empty()){
	     while(!s1.empty()){
	         Node* temp = s1.top();
	         s1.pop();
	         ans.push_back(temp->data);
	         if(temp->left){
	         s2.push(temp->left);
	         }
	         if(temp->right){
	         s2.push(temp->right);
	     }
	     }
	     while(!s2.empty()){
	         Node* temp2 = s2.top();
	         s2.pop();
	         ans.push_back(temp2->data);
	         if(temp2->right){
	         s1.push(temp2->right);
	         }
	         if(temp2->left){
	         s1.push(temp2->left);
	     }
	     }
	 }
	 return ans;
}