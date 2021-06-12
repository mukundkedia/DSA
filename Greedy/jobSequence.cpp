//https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1#

public:
    static bool comp(pair<int,int> j1,pair<int,int> j2){
      
        return j1.second>j2.second;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        vector<int> ret;
      vector<pair<int,int>> vec;
      for(int i=0;i<n;i++){
          vec.push_back({arr[i].dead,arr[i].profit});
      }
      sort(vec.begin(),vec.end(),comp);
      int res=0;
      int curr = 0;
      int count=0;
      bool done[100]={0};
      for(int i=0;i<n;i++){
          for(int j=vec[i].first-1;j>=0;j--){
              if(!done[j]){
                  done[j]=1;
                  curr+=1;
                  res+=vec[i].second;
                  break;
              }
          }
      }
      ret.push_back(curr);
      ret.push_back(res);
      
      return ret;
    } 