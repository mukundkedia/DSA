//https://practice.geeksforgeeks.org/problems/largest-number-in-k-swaps-1587115620/1


#include<bits/stdc++.h>
using namespace std;

void findMax(string str,int k,string &max){
        
        if(str>max){
            max=str;
        }
        
        if(k==0){
            return;
        }
        
        for(int i=0;i<str.length();i++){
            for(int j=i+1;j<str.length();j++){
                if(str[i]<str[j]){
                    swap(str[i],str[j]);
                    findMax(str,k-1,max);
                    swap(str[i],str[j]);
                }
            }
        }
    }
    string findMaximumNum(string str, int k)
    {
       int len = str.size();
       string max = str;
       findMax(str,k,max);
       return max;
    }