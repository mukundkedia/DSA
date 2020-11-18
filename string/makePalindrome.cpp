//https://www.geeksforgeeks.org/make-largest-palindrome-changing-k-digits/

#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main()
{
	string s;
    cin>>s;
    string palin = s;
    int k;
    cin>>k;
    int l=0,r=s.size()-1;
    while(l<r){
        if(s[l]!=s[r]){
        palin[l]=palin[r]=max(s[l],s[r]);
            k--;
        }
        l++;
        r--;
    }
    if(k<0){
        cout<<"Not possible";
    }
    l=0,r=s.size()-1;
   	while(l<=r){
        
        if(l==r){
            if(k>0){
            palin[l]='9';
        }
        }
        if(palin[l]<'9'){
            if(k>=2 and (s[l]==palin[l] and s[r]==palin[r])){
                palin[l]=palin[r]='9';
               	k-=2;
            }
            else if(k>=1 and (s[l]!=palin[l] || s[r]!=palin[r])){
                palin[l]=palin[r]='9';
                k-=1;
            }
           }
         l++;
            r--;
    }
    cout<<palin;
}