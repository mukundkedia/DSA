//https://leetcode.com/problems/palindromic-substrings/

//https://leetcode.com/problems/palindromic-substrings/discuss/789200/Simple-C%2B%2B-with-description

//https://www.youtube.com/watch?v=XmSOWnL6T_I

class Solution {
public:
    int countSubstrings(string s) {
        int len =  s.size();
   
        int count=0;
        vector<vector<bool>>dp(len,vector<bool>(len,false));
        for(int g=0;g<len;g++){
           for(int i=0,j=g;j<len;i++,j++){
               if(g==0){
                   dp[i][j]=true;
               }
               else if(g==1){
                   if(s[i]==s[j]){
                       dp[i][j]=true;
                   }
                   else{
                       dp[i][j]=false;
                   }
               }
               else{
                   if(s[i]==s[j] and dp[i+1][j-1]==true){
                       dp[i][j]=true;
                   }
                   else{
                       dp[i][j]=false;
                   }
               }
               if(dp[i][j]){
                   count++;
               }
           }
        }
        return count;
    }
};

//Another one o(n*n) and  o(1)

#include <bits/stdc++.h>
using namespace std;

int main() {
	//code	return 0;
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    int maxlength=1;
	    int len = s.size();
	    int start=0;
	    int low,high;
	    for(int i=1;i<len;i++){
	        low=i-1;
	        high=i;
	        while(low>=0 and high<len and s[low]==s[high]){
	            if(high-low+1>maxlength){
	                start=low;
	                maxlength=high-low+1;
	            }
	            low--;
	            high++;
	        }
	        low=i-1;
	        high=i+1;
	        while(low>=0 and high<len and s[low]==s[high]){
	            if(high-low+1>maxlength){
	                start=low;
	                maxlength=high-low+1;
	            }
	            low--;
	            high++;
	        }
	    }
	    cout<<s.substr(start,maxlength)<<"\n";
	}
}