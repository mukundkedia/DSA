//https://www.geeksforgeeks.org/check-for-identical-bsts-without-building-the-trees/
//PC
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct Node 
{ 
    int key; 
    struct Node *left, *right; 
}; 
  
Node * newNode(int k) 
{ 
    Node *temp = new Node; 
    temp->key = k; 
    temp->left = temp->right = NULL; 
    return temp; 
}

bool checkForSameBST(vector<int> a,vector<int> b){
    int n = a.size();
    int m = b.size();
    if(a!=b){
        return false;
    }
    if(n==0){
        return true;
    }
    if(a[0]!=b[0]){
        return false;
    }
    vector<int> al,ar,bl,br;
    for(int i=1;i<n;i++){
        if(a[i]<a[0]){
            al.push_back(a[i]);
        }
        else{
            ar.push_back(a[i]);
        }

             if(b[i]<b[0]){
            bl.push_back(b[i]);
        }
        else{
            br.push_back(b[i]);
        }
}
return checkForSameBST(al,ar) && checkForSameBST(bl,br);
    }

int main()
{
	vector<int> a = {8, 3, 6, 1, 4, 7, 10, 14, 13};  
    vector<int> b = {8, 10, 14, 3, 6, 4, 1, 7, 13};  
    cout<<checkForSameBST(a,b)<<endl;
    return 0;
}
