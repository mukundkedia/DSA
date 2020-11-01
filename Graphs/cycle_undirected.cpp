#include<bits/stdc++.h>
using namespace std;
vector<int> g[500];
vector<int> vis(500,0);

void addEdge(int u,int v,bool para){
g[u].push_back(v);
if(para==true){
g[v].push_back(u);
}
}

bool dfs(int node,int parent){ //1 0
    vis[node]=true;
    for(auto it:g[node]){
        if(!vis[it]){
            if(dfs(it,node)){
                return true;
            }
        }
            else if(it!=parent){
                return true;
            }
        }
        return false;
    }


int main(){
    addEdge(1,2,true);
    addEdge(2,3,true);
    // addEdge(4,1,true);
    addEdge(5,1,true);
    addEdge(5,4,true);
    addEdge(7,5,true);
    addEdge(6,7,true);
    addEdge(4,6,true);
    dfs(1,0);
}

