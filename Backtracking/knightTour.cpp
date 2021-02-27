#include<bits/stdc++.h>
using namespace std;

#define N 8

bool isValid(int x,int y,int sol[N][N]){
  return (x>=0 and x<N and y>=0 and y<N and sol[x][y]==-1);
}

bool solve(int cx,int cy,int cnt,int sol[N][N],int xmove[N], int ymove[N]){
  if(cnt==N*N){
    return true;
  }
  for(int k=0;k<N;k++){
      if(isValid(cx+xmove[k],cy+ymove[k],sol)){
          sol[cx+xmove[k]][cy+ymove[k]]=cnt;
          if(solve(cx+xmove[k],cy+ymove[k],cnt+1,sol,xmove,ymove)){
            return 1;
          }
          else{
             sol[cx+xmove[k]][cy+ymove[k]]=-1;
          }
      }
  }
  return 0;
}

int main(){
  int sol[N][N];
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      sol[i][j]=-1;
    }
  }
  sol[0][0]=0;

  int xmove[8]={2,2,-2,-2,1,1,-1,-1};
  int ymove[8]={1,-1,1,-1,2,-2,2,-2};

  if(solve(0,0,1,sol,xmove,ymove)){
    for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cout<<sol[i][j]<<" ";
    }
    cout<<"\n";
  }
  }
}