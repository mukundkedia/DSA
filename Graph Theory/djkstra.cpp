#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> adj[100];

void addEdge(int u,int v,int weight){
  adj[u].push_back({v,weight});
  adj[v].push_back({u,weight});
}


int main(){

    addEdge(1,2,2);
    addEdge(2,5,5);
    addEdge(1,4,1);
    addEdge(3,4,3);
    addEdge(3,5,1);
    addEdge(2,3,4);

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(100,INT_MAX);
   //SRC=1
   dist[1]=0;
   pq.push({0,1});
   while(!pq.empty()){
     int distance = pq.top().first;
     int node = pq.top().second;
     pq.pop();
     for(auto it:adj[node]){
       if(distance+it.second<dist[it.first]){
         dist[it.first]=distance+it.second;
         pq.push({dist[it.first],it.first});
       }
     }
   }
   for(int i=1;i<6;i++){
     cout<<dist[i]<<" ";
   }
} 