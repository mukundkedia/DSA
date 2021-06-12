#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[100];

void addEdge(int u,int v,int weight){
  adj[u].push_back({v,weight});
  adj[v].push_back({u,weight});
}


int main(){

    addEdge(0,1,2);
    addEdge(1,2,3);
    addEdge(0,3,6);
    addEdge(3,1,8);
    addEdge(4,1,5);
    addEdge(2,4,7);
    vector<int> key(10),parent(10);
    vector<bool> mstSet(10);
    for(int i=0;i<10;i++){
      key[i]=INT_MAX;
      parent[i]=-1;
      mstSet[i]=false;
    }

priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;  //{value,index}

    key[0]=0;
    parent[0]=-1;

    pq.push({0,0});

    int n=5; //no. of vertices
    
    for(int count=0;count<n-1;count++){  //since there are n-1 edges are there in MST

      int u = pq.top().second;
      pq.pop();
      
        mstSet[u]=true;
        for(auto it:adj[u]){
          int v=it.first;
          int weight = it.second;
          if(!mstSet[it.first] and key[v]>weight){
            parent[v]=u;
            key[v]=weight;
            pq.push({key[v],v});
            
          }
        }
    }
    for(int i=1;i<n;i++){

    }
}
