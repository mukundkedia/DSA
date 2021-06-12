#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];

void addEdge(int u,int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}

//color 0 and 1

//returns true if bipartite
bool checkBipartite(int src,vector<int>& col){
queue<int> q;
q.push(src);
col[src]=1;
while(!q.empty()){
  int node = q.front();
  q.pop();
  for(auto it:adj[node]){
    if(col[it]==-1){
      q.push(it);
      col[it]=1-col[node];
    }
    else if(col[it]==col[node]){
      return false;
    }
  }
}
return true;
}

int main(){
    addEdge(1,3);
    addEdge(3,5);
    addEdge(2,4);
    addEdge(2,5);
    addEdge(4,6);
  vector<int> col(100,-1);
  for(int i=1;i<100;i++){
    if(col[i]==-1){
      if(!checkBipartite(i,col)){
        return false;
      }
    }
  }
  return true;
}