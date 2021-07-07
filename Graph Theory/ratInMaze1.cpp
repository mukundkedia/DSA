//https://practice.geeksforgeeks.org/problems/rat-in-a-maze-problem/1

class Solution{
    public:
    int rc[4]={1,0,0,-1};
    int cc[4]={0,1,-1,0};
    char dir[4]={'D','R','L','U'};
    
    bool isValid(int r,int c,int n,vector<vector<int>> &m){
        if(r<0 || r>=n || c<0 || c>=n || m[r][c]==0){
            return false;
        }
        return true;
    }
    
    void solve(int r,int c,vector<vector<int>> &m,int n,vector<string>& ans,string s){
        if(r==n-1 and c==n-1){
            ans.push_back(s);
            return;
        }
        for(int i=0;i<4;i++){
            if(isValid(r+rc[i],c+cc[i],n,m)){
                s.push_back(dir[i]);
                m[r][c]=0;
                solve(r+rc[i],c+cc[i],m,n,ans,s);
                m[r][c]=1;
                s.pop_back();
        }
    }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
         if(m[0][0]==0 || m[n-1][n-1]==0){
      return ans;
  }
        string str="";
        solve(0,0,m,n,ans,str);
        sort(ans.begin(),ans.end());
        return ans;
    }
};