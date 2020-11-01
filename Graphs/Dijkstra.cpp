#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> g[500]; 
vector<int> vis(500,0);

void addEdge(int u,int v,int w){
g[u].push_back({v,w});
g[v].push_back({u,w});

}

int main(){
addEdge(1,2,6);
addEdge(1,3,4);
addEdge(3,2,1);
addEdge(5,2,6);
addEdge(6,5,1);
addEdge(5,4,3);
addEdge(4,6,11);
addEdge(3,4,2);
int src =1;
set<pair<int,int>> setds; // distance,node
setds.insert({0,src});
vector<int> dist(7,INT_MAX);
dist[src]=0;
while(!setds.empty()){
    pair<int,int> tmp = *(setds.begin());
    setds.erase(setds.begin());
    int u = tmp.second; //node
    vector<pair<int,int>>:: iterator it;
    for(it=g[u].begin();it!=g[u].end();it++){
            int v = (*it).first;
            int w = (*it).second; //weight
            if(dist[v]>dist[u]+w){
                if(dist[v]!=INT_MAX){
                    setds.erase({dist[v],v});
                }
                dist[v]=dist[u]+w;
                setds.insert({dist[v],v});
            }
    }
}
for(int i=1;i<7;i++){
    cout<<dist[i]<<" ";
}
}