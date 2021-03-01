#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/count-number-of-ways-to-partition-a-set-into-k-subsets/
 
//nos = no. of set

void  solve(int i,int n,int k,int nos,vector<vector<int>> res){

  if(i>n){
    if(nos==k){
        for(auto it:res){
          for(auto it2:it){
            cout<<it2<<" ";
          }
          cout<<"\n";
        }
    }
    return;
  }

  for(int j=0;j<res.size();j++){
    if(res[j].size()>0){
      res[j].push_back(i); 
      solve(i+1,n,k,nos,res);
      res[j].pop_back();
    }
    else{
      res[j].push_back(i);
      solve(i+1,n,k,nos+1,res);
      res[j].pop_back();
      break;
    }
  }

}

int main(){
  int n,k;
  cin>>n>>k;
  vector<vector<int>> res(k);
 
  solve(1,n,k,0,res);
}