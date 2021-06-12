#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];

void addEdge(int u,int v){
  adj[u].push_back(v);
}



int main(){

    addEdge(4,0);
    addEdge(4,1);
    addEdge(3,1);
    addEdge(2,3);
    addEdge(5,2);
    addEdge(5,0);
    queue<int> q;
    vector<int> in(100,0);

    for(int i=0;i<6;i++){
      for(auto it:adj[i]){
        in[it]++;
      }
    }

    for(int i=0;i<6;i++){
      if(in[i]==0){
        q.push(i);
      }
    }

    while(!q.empty()){
      int front = q.front();
      q.pop();
      cout<<front<<" ";
      for(auto it:adj[front]){
        in[it]--;
        if(in[it]==0){
          q.push(it);
        }
      }
    }
    
}