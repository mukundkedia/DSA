//https://www.geeksforgeeks.org/given-a-sequence-of-words-print-all-anagrams-together/

#include<bits/stdc++.h>
using namespace std;


vector<vector<string> > Anagrams(vector<string>& string_list) 
{
   
   map<map<char,int>,vector<string>> my_map;
   for(string str:string_list){
       map<char,int> temp_map;
       vector<string> temp_list;
       for(int i=0;i<str.length();i++){
           temp_map[str[i]]++;
       }
       auto it = my_map.find(temp_map);
       if(it!=my_map.end()){
           it->second.push_back(str);
       }
       else{
           temp_list.push_back(str);
           my_map[temp_map]=temp_list;
       }
   }
   
   vector<vector<string>> ans;
   
   for(auto it=my_map.begin();it!=my_map.end();it++){
       ans.push_back(it->second);
   }
   return ans;
   
}