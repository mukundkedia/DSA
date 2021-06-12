#include<bits/stdc++.h>
using namespace std;

vector<int> adj[100];

void addEdge(int u,int v){
  adj[u].push_back(v);
  adj[v].push_back(u);
}

//color 0 and 1

//returns true if bipartite
bool checkBipartite(int src,vector<int>& col,int color){
    col[src]=color;
    for(auto it:adj[src]){
      if(col[it]==-1){
        if(!checkBipartite(it,col,1-color)){
          return false;
        }
      }
      else if(col[it]==col[src]){
          return false;
      }
    }
    return true;
}

int main(){
    addEdge(1,2);
    addEdge(3,2);
    addEdge(3,4);
    addEdge(4,5);
    addEdge(5,7);
    addEdge(8,7);
    addEdge(2,5);
    
  vector<int> col(100,-1);
  for(int i=1;i<100;i++){
    if(col[i]==-1){
      if(!checkBipartite(i,col,1)){
        cout<<"false";
      }
    }
  }
  return true;
}