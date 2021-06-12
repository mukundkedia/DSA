https://www.geeksforgeeks.org/water-connection-problem/

int dfs(int w,int dm[100],int st[100]){
        if(st[w]==0){
            return w;
        }
        if(ans>dm[w]){
            ans=dm[w];
        }
        return dfs(st[w],dm,st);
    }
    
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        int st[100];
        int ed[100];
        int dm[100];
        vector<vector<int>> temp;
        for(int i=0;i<p;i++){
            st[a[i]]=b[i];
            ed[b[i]]=a[i];
            dm[a[i]]=d[i];
        }
        for(int i=1;i<=n;i++){
            if(ed[i]==0 and st[i]){
                int ans = INT_MAX;
                int end = dfs(i,dm,st);
                vector<int> res;
                res.push_back(i);
                res.push_back(end);
                res.push_back(ans);
                temp.push_back(res);
            }
        }
        return temp;
    }