#include<bits/stdc++.h>
using namespace std;
vector<int> g[500];
vector<int> vis(500,0);

void addEdge(int u,int v){
g[u].push_back(v);
g[v].push_back(u);
}

void bfs(int val){
    queue<int> q;
    q.push(val);
    vis[val]=true;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        cout<<t<<" ";
        for(auto ele:g[t]){
            if(vis[ele]==0){
                vis[ele]=1;
                q.push(ele);
            }
        }
    }
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
    bfs(1);
}