//https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#

public:
    static bool comp(pair<int,int> a,pair<int,int> b){
            return a.second<b.second;
        
    }
    //Function to find the maximum 
    int maxMeetings(int start[], int end[], int n)
    {
      vector<pair<int,int>> vec;
      for(int i=0;i<n;i++){
          vec.push_back({start[i],end[i]});
      }
      sort(vec.begin(),vec.end(),comp);
      int ans=1;
      int endtime=vec[0].second;
      for(int i=1;i<n;i++){
          if(vec[i].first > endtime){
              ans++;
              endtime=vec[i].second;
          }
      }
      return ans;
    }
