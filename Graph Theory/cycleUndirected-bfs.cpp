#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];

void addEdge(int u,int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}

bool checkCycle(int node,vector<int> &vis){
  queue<pair<int,int>> q;
  vis[node]=1;
  q.push({node,-1});
  while(!q.empty()){
    int topNode = q.front().first;
    int par = q.front().second;
    q.pop();
    for(auto it:adj[topNode]){
      if(!vis[it]){
        q.push({it,topNode});
        vis[it]=1;
      }
      else if(it!=par){
        return true;
      }
    }
  }
  return false;
}

int main(){
    addEdge(1,3);
    addEdge(3,5);
    addEdge(2,4);
    addEdge(2,5);
    addEdge(4,6);
  vector<int> vis(100,0);
  if(checkCycle(1,vis)){
    cout<<"true";
  }
  else{
    cout<<"false";
  }
}