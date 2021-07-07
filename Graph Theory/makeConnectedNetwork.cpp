//https://leetcode.com/problems/number-of-operations-to-make-network-connected/

class Solution {
public:
    void dfs(int node,vector<int>& vis,vector<int> adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        int c=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                c++;
                dfs(i,vis,adj);
            }
        }
        int red = connections.size()-((n-1)-(c-1));
        if(red>=c-1){
            return c-1;
        }
        return -1;
    }
};