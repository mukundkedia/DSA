//https://leetcode.com/problems/course-schedule-ii
//LB

class Solution {
public:
    vector<int> g[5000]; 
    
    
    void addEdge(int u,int v){
        g[u].push_back(v);
}
    
    void dfs(int val,stack<int>& st,vector<int>& vis){
        vis[val]=1;
        for(auto ele:g[val]){
            if(!vis[ele]){
                dfs(ele,st,vis);
            }
        }
        st.push(val);
    }
    
    bool dfs11(int node,vector<int>& vis11,vector<int>& rec){
        if(vis11[node]==0){
            vis11[node]=1;
            rec[node]=1;
            for(auto it:g[node]){
                if(!vis11[it] and dfs11(it,vis11,rec)){
                    return true;
                }
                else if(rec[it]==1){
                    return true;
                }
            }
        }
        rec[node]=0;
        return false;
    }
    
    bool detectCycle(int n){
        vector<int> vis11(n+1,0);
        vector<int> rec(n+1,0);
        for(int i=0;i<n;i++){
            if(!vis11[i]){
                bool ans = dfs11(i,vis11,rec);
                if(ans==true){
                    return true;
                }
            }
        }
        return false;
    }
    
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> vis(numCourses+1,0);
        vector<int> ans;
        if(prerequisites.size()==0){
            for(int i=0;i<numCourses;i++){
                ans.push_back(i);
            }
            return ans;
        }
        for(int i=0;i<prerequisites.size();i++){
            addEdge(prerequisites[i][1],prerequisites[i][0]);
        }
    
    if(detectCycle(numCourses)){
        return ans;
    }
    
    stack<int> st;
    for(int i=0;i<numCourses;i++){
        if(!vis[i]){
            dfs(i,st,vis);
        }
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
    }
};