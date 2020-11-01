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

void dfs(int val,stack<int> &st){
    vis[val]=1;
    for(auto ele:g[val]){
        if(!vis[ele]){
            dfs(ele,st);
        }
    }
    st.push(val);
}

//Directed Acyclic Graph

int main(){
    addEdge(5,0,false);
    addEdge(5,2,false);
    addEdge(0,2,false);
    addEdge(4,2,false);
    addEdge(0,3,false);
    addEdge(3,1,false);
    addEdge(4,1,false);
    stack<int> st;
    for(int i=0;i<=5;i++){
        if(!vis[i]){
            dfs(i,st);
        }
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}