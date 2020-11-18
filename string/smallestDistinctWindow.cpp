//https://practice.geeksforgeeks.org/problems/smallest-distant-window

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int ans=INT_MAX;
        vector<int> freqa(256,0);
        vector<int> freqb(256,0);
        int count=0;
        int tsize=0;
        for(char c:s){
           if(freqb[c]==0){
                freqb[c]++;
                tsize++;
            }
        }
       int win_left=0;
       int len = INT_MAX;
       int ans_left;
       for(int i=0;i<s.size();i++){
           if(freqb[s[i]]>0 and freqb[s[i]]>freqa[s[i]]){
               count++;
           }
           freqa[s[i]]++;
           if(count==tsize){
               while(win_left<i and freqa[s[win_left]]>freqb[s[win_left]]){
                   freqa[s[win_left]]--;
                   win_left++;
               }
               if(ans>i-win_left+1){
                   ans=i-win_left+1;
                   ans_left = win_left;
               }
             }
       }
       cout<<ans<<"\n";
    }
}