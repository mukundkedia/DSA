#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];

void addEdge(int u,int v){
  adj[u].push_back(v);
}


bool checkCycle(int node,vector<int>& vis,vector<int> dfsVis){
    vis[node]=1;
    dfsVis[node]=1;
    for(auto it:adj[node]){
      if(vis[it]){
        if(dfsVis[it]==1){
          return true;
        }
      }
      else{
          if(checkCycle(it,vis,dfsVis)){
            return true;
          }
      }
    }
    dfsVis[node]=0;
    return false;
}

int main(){
    addEdge(1,2);
    addEdge(3,2);
    addEdge(3,4);
    addEdge(4,5);
    addEdge(5,7);
    addEdge(7,8);
    addEdge(2,5);
    addEdge(8,1);
    
  vector<int> vis(100,0);
  vector<int> dfsvis(100,0);
  for(int i=1;i<8;i++){
    if(!vis[i]){
      if(checkCycle(i,vis,dfsvis)){
        cout<<"true";
        break;
      }
    }
  }
  return false;
}