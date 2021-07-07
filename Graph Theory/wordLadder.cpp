//https://leetcode.com/problems/word-ladder/


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet;//set of words
        bool isPresent = false;
        for(int i=0;i<wordList.size();i++){
            if(endWord==wordList[i]){
                isPresent=true;
            }
            wordSet.insert(wordList[i]);
        }
        if(!isPresent){
            return 0;
        }
        queue<string> q;
        q.push(beginWord);
        int depth=0;
        while(!q.empty()){
            depth+=1;
            int len=q.size();
            while(len--){
                string curr = q.front();
                q.pop();
                for(int i=0;i<curr.size();i++){
                    string temp=curr;
                    for(char c='a';c<='z';c++){
                        temp[i]=c;
                        if(temp==curr){
                            continue;
                        }
                        if(temp==endWord){
                            return depth+1;
                        }
                        if(wordSet.find(temp)!=wordSet.end()){
                            q.push(temp);
                            wordSet.erase(temp);
                        }
                    }
                }
            }
        }
        return 0;
    }
};