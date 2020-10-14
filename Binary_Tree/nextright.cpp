#include<bits/stdc++.h>
using namespace std; 
  
// A Binary Tree Node 
struct node 
{ 
    struct node *left, *right; 
    int key; 
}; 

node* newNode(int key) 
{ 
    node *temp = new node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

node* nextRight(node *root, int k) 
{ 
    // Base Case 
    if (root == NULL) 
        return 0; 
  
    // Create an empty queue for level order tarversal 
    queue<node *> qn; // A queue to store node addresses 
    queue<int> ql;   // Another queue to store node levels 
  
    int level = 0;  // Initialize level as 0 
  
    // Enqueue Root and its level 
    qn.push(root); 
    ql.push(level); 
  
    // A standard BFS loop 
    while (qn.size()) 
    { 
        // dequeue an node from qn and its level from ql 
        node *node = qn.front(); 
        level = ql.front(); 
        qn.pop(); 
        ql.pop(); 
  
        // If the dequeued node has the given key k 
        if (node->key == k) 
        { 
            // If there are no more items in queue or given node is 
            // the rightmost node of its level, then return NULL 
            if (ql.size() == 0 || ql.front() != level) 
               return NULL; 
  
            // Otherwise return next node from queue of nodes 
            return qn.front(); 
        } 
  
        // Standard BFS steps: enqueue children of this node 
        if (node->left != NULL) 
        { 
            qn.push(node->left); 
            ql.push(level+1); 
        } 
        if (node->right != NULL) 
        { 
            qn.push(node->right); 
            ql.push(level+1); 
        } 
    } 
  
    // We reach here if given key x doesn't exist in tree 
    return NULL; 
} 

void test(node *root, int k) 
{ 
    node *nr = nextRight(root, k); 
    if (nr != NULL) 
      cout << "Next Right of " << k << " is " << nr->key << endl; 
    else
      cout << "No next right node found for " << k << endl; 
} 
  

int main() 
{ 
    // Let us create binary tree given in the above example 
    node *root = newNode(10); 
    root->left = newNode(2); 
    root->right = newNode(6); 
    root->right->right = newNode(5); 
    root->left->left = newNode(8); 
    root->left->right = newNode(4); 
  
    test(root, 10); 
    test(root, 2); 
    test(root, 6); 
    test(root, 5); 
    test(root, 8); 
    test(root, 4); 
    return 0; 
} 
