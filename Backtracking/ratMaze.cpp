//KM
//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

#include<bits/stdc++.h>
using namespace std;

bool isSafe(int row,int col,int m[MAX][MAX],int n){
    if(row<0 || col<0 || row>=n || col>=n || !m[row][col]){
        return false;
    }
    return true;
}

void solve(int m[MAX][MAX],int n,int row,int col,string &curpath,vector<string> &res){
    if(row==n-1 and col==n-1){
        res.push_back(curpath);
    }
    int rchange[]={-1,1,0,0};
    int cchange[]={0,0,-1,1};
    char dir[]={'U','D','L','R'};
    for(int i=0;i<4;i++){
        if(isSafe(row+rchange[i],col+cchange[i],m,n)){
            m[row][col]=0;
            curpath.push_back(dir[i]);
            solve(m,n,row+rchange[i],col+cchange[i],curpath,res);
            m[row][col]=1;
            curpath.pop_back();
        }
    }
}

vector<string> findPath(int m[MAX][MAX], int n) {
  vector<string> paths;
  if(m[0][0]==0 || m[n-1][n-1]==0){
      return paths;
  }
  int row=0,col=0;
  string curpath="";
  solve(m,n,row,col,curpath,paths);
  sort(paths.begin(),paths.end());
  return paths;
}
