#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[100];

void addEdge(int u,int v,int weight){
  adj[u].push_back({v,weight});
}



void dfs(int node,vector<int>& vis,stack<int>& st){
  vis[node]=1;
  for(auto it:adj[node]){
    if(!vis[it.first]){
      dfs(it.first,vis,st);
    }
  }
  st.push(node);
}

void shortestPath(int src,vector<int>& dist,stack<int>& topo){
   dist[src]=0;
   while(!topo.empty()){
      int node = topo.top();
      topo.pop();
      if(dist[node]!=INT_MAX){
          for(auto it:adj[node]){
            if(dist[node]+it.second<dist[it.first]){
              dist[it.first]=dist[node]+it.second;
            }
        
      }
      }
      
    }

    for(int i=0;i<6;i++){
      cout<<dist[i]<<" ";
    }
}

int main(){

    addEdge(0,1,2);
    addEdge(1,2,3);
    addEdge(2,3,6);
    addEdge(0,4,1);
    addEdge(4,2,2);
    addEdge(4,5,4);
    addEdge(5,3,1);

    stack<int> topo;
    vector<int> vis(6,0);
    vector<int> dis(6,INT_MAX);

    for(int i=0;i<6;i++){
      if(!vis[i]){
        dfs(i,vis,topo);
      }
    }
    
  
    shortestPath(0,dis,topo);
   



   
}