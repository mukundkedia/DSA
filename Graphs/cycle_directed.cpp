#include<bits/stdc++.h>
using namespace std;
vector<int> g[500]; 
vector<int> vis(500,0);
vector<int> rec(500,0);

void addEdge(int u,int v,bool para){
g[u].push_back(v);
if(para==true){
g[v].push_back(u);
}
}

bool dfs(int node){
    if(vis[node]==0){
        vis[node]=1;
        rec[node]=1;

        for(auto it:g[node]){
            if(!vis[it] and dfs(it)){
                return true;
            }
            else if(rec[it]==1){
                return true;
            }
        }                                                                                    
                                                                                                                                                                                                                                    
    }
    rec[node]=0;
    return false;
     
}

int main(){
    addEdge(1,2,false);
    addEdge(2,3,false);
    addEdge(4,1,false);
    addEdge(5,1,false);
    addEdge(5,4,false);
    addEdge(7,5,false);
    addEdge(6,7,false);
    addEdge(4,6,false);


    for(int i=1;i<=6;i++){
        if(!vis[i]){
            bool ans = dfs(i);
            if(ans==true){
                cout<<"true"<<"\n";
                break;
            }
        }
    }
}