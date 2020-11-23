//https://www.geeksforgeeks.org/count-total-anagram-substrings/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
    cin>>s;
    map<vector<int>,int> map1;
    
    int len=s.size();
    for(int i=0;i<len;i++){
        	vector<int> freq(26,0);
        for(int j=i;j<len;j++){
            freq[s[j]-'a']++;
            map1[freq]++;
        }
    }
    int ans=0;
    for(auto it=map1.begin();it!=map1.end();it++){
        ans+=(it->second)*(it->second-1)/2;
    }
    cout<<ans<<"\n";
}