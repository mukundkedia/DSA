//https://www.geeksforgeeks.org/find-kth-character-of-decrypted-string/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
	string s;
    cin>>s;
    string ans="";
    for(int i=0;s[i]!='\0';){
        string temp="";
    	int freq=0;
        
        while(s[i]>='a' and s[i]<='z'){
            temp+=s[i];
            i++;
        }
        while(s[i]>='0' and s[i]<='9'){
            freq = freq*10 + (s[i]-'0');
            i++;
        }
        for(int j=1;j<=freq;j++){
            ans+=temp;
        }
    }
    cout<<ans;
}