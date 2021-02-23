//

#include<bits/stdc++.h>?
using namespace std;

bool isSafe(int u,int col,bool graph[101][101],vector<int> color,int V,int m){
    for(int i=0;i<V;i++){
        if(graph[u][i]==1 and color[i]==col){
            return false;
        }
    }
    return true;
}

bool mcolor(int u,bool graph[101][101],vector<int> color,int V,int m){
    if(u==V){
        return true;
    }
    for(int i=0;i<m;i++){
        if(isSafe(u,i,graph,color,V,m)){
            color[u]=i;
            bool temp = mcolor(u+1,graph,color,V,m);
            if(temp){
                return true;
            }
             color[u]=-1;
        }
    }
   
    return false;
}

bool graphColoring(bool graph[101][101], int m, int V) {
    int u=0;
    vector<int> color(V,-1);
  
    return mcolor(u,graph,color,V,m);
}