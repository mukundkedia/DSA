//https://www.geeksforgeeks.org/anagram-substring-search-search-permutations/

class Solution{
public:
	int search(string pat, string txt) {
	    vector<int> fp(26,0);
	    vector<int> ft(26,0);
	    for(char c:pat){
	        fp[c-'a']++;
	    }
	    int ans=0;
	    int sindex=0;
	    for(int i=0;i<txt.size();i++){
	        while(i<pat.size()){
	            ft[txt[i]-'a']++;
	            i++;
	        }
	        if(fp==ft){
	            ans++;
	        }
	        ft[txt[sindex]-'a']--;
	        sindex++;
	        ft[txt[i]-'a']++;
	    }
	    if(ft==fp){
	        ans++;
	    }
	    return ans;
	}

};