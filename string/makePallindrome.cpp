//https://www.geeksforgeeks.org/lexicographically-first-palindromic-string/

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void findfreq(string s,vector<int>& freq){
    int len = s.size();
    for(char c:s){
        freq[c-'a']++;
    }
}

bool possible(vector<int> freq,int len){
   	int count_odd=0;
       for(int i=0;i<26;i++){
            if(freq[i]%2!=0){
                count_odd++;
            }
       }
       if(len%2==0){
           if(count_odd>0){
               return false;
           }
       }
    if(len%2==1){
        if(count_odd!=1){
            return false;
        }
    }
    return true;
}

string findmid(vector<int>& freq){
    string res="";
    for(int i=0;i<26;i++){
        if(freq[i]%2==1){
            freq[i]--;
            res+=char(i+'a');
            return res;
        }
    }
    return res;
}

int main()
{
	string s;
    cin>>s;
    int len = s.size();
    vector<int> freq(26,0);
    findfreq(s,freq);
    if(possible(freq,len)){
        string oddlen = findmid(freq);
        string front="",rear="";
        for(int i=0;i<26;i++){
            string temp="";
            if(freq[i]!=0){
                char ch = char(i+'a');
                for(int j=1;j<=freq[i]/2;j++){
                    temp+=ch;
                }
                front=temp+front;
                rear=rear+temp;
            }
        }
        cout<<front+oddlen+rear;
    }
    else{
        cout<<"Not possible";
    }
}