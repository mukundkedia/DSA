//https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree/

#include <bits/stdc++.h>
using namespace std;

void addEdge(vector<int> G1[],int u,int v){
    G1[u].push_back(v);
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,e;
	    cin>>n>>e;
	    vector<int> G1[n],G2[n];
	    for(int i=0;i<e;i++){
	        int u,v;
	        cin>>u>>v;
	        addEdge(G1,u,v);
	    }
	    for(int i=0;i<e;i++){
	        int u,v;
	        cin>>u>>v;
	        addEdge(G2,u,v);
	    }
	    for(int i=0;i<n;i++){
	        reverse(G2[i].begin(),G2[i].end());
	    }
	    int flag=0;
	    for(int i=0;i<n;i++){
	        if(G1[i]!=G2[i]){
	            flag=1;
	        }
	    }
	    if(flag){
	        cout<<"0"<<"\n";
	    }
	    else{
	        cout<<"1"<<"\n";
	    }
	}
}