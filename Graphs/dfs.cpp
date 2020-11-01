#include<bits/stdc++.h>
using namespace std;
vector<int> g[500]; 
vector<int> vis(500,0);

void printBfs(int val){
    vis[val]=1;
    cout<<val<<" ";
    for(auto x: g[val]){
        if(vis[x]==0){
            printBfs(x);
        }
    }
}

void addEdge(int u,int v){
g[u].push_back(v);
g[v].push_back(u);
}

int main(){
    addEdge(1,2);
    addEdge(1,3);
    addEdge(3,5);
    addEdge(2,4);
    addEdge(2,5);
    addEdge(4,6);
    addEdge(4,5);
    addEdge(5,6);
    
    printBfs(1);
}