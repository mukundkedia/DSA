//https://www.geeksforgeeks.org/tug-of-war/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void solveTOW(int n,int vec[],bool curr_elements[],int selected_elements,bool soln[],int sum,int &min_diff,int curr_sum,int curr_pos){
    if(curr_pos==n){
      return;
    }
    if((n/2-selected_elements)>n-curr_pos){
        return;
    }
    solveTOW(n,vec,curr_elements,selected_elements,soln,sum,min_diff,curr_sum,curr_pos+1);
    curr_sum+=vec[curr_pos];
    curr_elements[curr_pos]=1;
    selected_elements++;
    
    if(selected_elements==n/2){
        if(abs(sum/2-curr_sum)<min_diff){
            min_diff = abs(sum/2-curr_sum);
            for(int i=0;i<n;i++){
                soln[i]=curr_elements[i];
            }
        }
    }
    else{
        solveTOW(n,vec,curr_elements,selected_elements,soln,sum,min_diff,curr_sum,curr_pos+1);
    }
    curr_elements[curr_pos]=0;
}

int main()
{
	int n;
    cin>>n;
    int vec[n];
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>vec[i];
        sum+=vec[i];
    }
  	bool curr_elements[n];
    bool soln[n];
    for(int i=0;i<n;i++){
        curr_elements[i]=soln[i]=0;
    }
    int min_diff = INT_MAX;
    solveTOW(n,vec,curr_elements,0,soln,sum,min_diff,0,0);
    for(int i=0;i<n;i++){
       if(soln[i]==1){
           cout<<vec[i]<<" ";
    }
    }
}