#include<bits/stdc++.h>
using namespace std;

bool isValid(int a,int b,int r,int c){
  return (a<r and a>=0 and b<c and b>=0);
}

void solve(int i,int j,int r,int c,vector<vector<int>>& res,vector<int> curr,vector<vector<int>> arr){
if(i==r-1 and j==c-1){
  curr.push_back(arr[i][j]);
  res.push_back(curr);
  return;
}
if(isValid(i,j,r,c)){
  curr.push_back(arr[i][j]);
}
else{
  return;
}
solve(i+1,j,r,c,res,curr,arr);
solve(i,j+1,r,c,res,curr,arr);

}

int main(){
  int a,b;
  cin>>a>>b;
  vector<vector<int>> arr(a,vector<int>(b,0));
  for(int i=0;i<a;i++){
    for(int j=0;j<b;j++){
      cin>>arr[i][j];
    }
  }
  vector<vector<int>> res;
  vector<int> curr;
  solve(0,0,a,b,res,curr,arr);
  for(int i=0;i<res.size();i++){
    for(int j=0;j<res[i].size();j++){
      cout<<res[i][j]<<" ";
    }
    cout<<"\n";
  }

}