//https://www.geeksforgeeks.org/maximum-sum-nodes-binary-tree-no-two-adjacent/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* left, *right;
    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

pair<int,int> helper(Node* root){
    if(!root){
        pair<int,int> sum(0,0);
        return sum;
    }
    pair<int,int> sum1 = helper(root->left);
    pair<int,int> sum2 = helper(root->right);
    pair<int,int> sum;
    sum.first = sum1.second+sum2.second+root->data;
    sum.second = max(sum1.first,sum1.second)+max(sum2.first,sum2.second);
    return sum;
}

int maxSum(Node* root){
    pair<int,int> res = helper(root);
    return max(res.first,res.second);
}


int main()
{
	 Node *root= new Node(10);
    root->left= new Node(1);
    root->left->left= new Node(2);
    root->left->left->left= new Node(1);
    root->left->right= new Node(3);
    root->left->right->left= new Node(4);
    root->left->right->right= new Node(5);
    cout << maxSum(root);
    return 0;
}