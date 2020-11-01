#include<bits/stdc++.h>
using namespace std;
vector<int> g[500];

void addEdge(int u,int v){
g[u].push_back(v);
g[v].push_back(u);
}

void print(){
    for(auto it:g){
        for(auto x:it){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}

int main(){
    
  addEdge(0,1);
  addEdge(0,2);
  addEdge(1,2);
  addEdge(3,1);
  addEdge(1,4);
  addEdge(4,3);
  print();
}