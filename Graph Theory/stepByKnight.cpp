//https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1

class Solution 
{
    public:
    int x[8]={1,1,2,2,-1,-1,-2,-2};
    int y[8]={2,-2,1,-1,2,-2,1,-1};
    
    bool isSafe(int r,int c,int N,vector<vector<int>> vis){
        if(r>=1 and r<=N and c>=1 and c<=N){
            return true;
        }
        return false;
    }
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N){
	
	if(KnightPos[0]==TargetPos[0] and KnightPos[1]==TargetPos[1])
	{
	    return 0;
	}
        int ans=0;
        queue<pair<int,int>> q;
        vector<vector<int>> vis(N+1,vector<int>(N+1,0));
        
        q.push({KnightPos[0],KnightPos[1]});
        vis[KnightPos[0]][KnightPos[1]]=1;
        while(!q.empty()){
            ans++;
            int len = q.size();
            while(len--){
                auto pos = q.front();
                q.pop();
                for(int i=0;i<8;i++){
                    int r = pos.first + x[i];
                    int c = pos.second + y[i];
                    if(isSafe(r,c,N,vis) and !vis[r][c]){
                        if(r==TargetPos[0] and c==TargetPos[1]){
                            return ans;
                        }
                        else{
                            q.push({r,c});
                            vis[r][c]=1;
                        }
                    }
                }
            }
        }
        return -1;
	}
};