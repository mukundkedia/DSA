//https://practice.geeksforgeeks.org/problems/page-faults-in-lru5603/1#

int pageFaults(int N, int C, int pages[]){
        //5->0   //5,0,1,3
       unordered_set<int> s;
       unordered_map<int,int> index;
       int pf=0;
       for(int i=0;i<N;i++){
           if(s.size()<C){
               if(s.find(pages[i])==s.end()){
                   s.insert(pages[i]);
                   pf++;
               }
               index[pages[i]]=i;;
           }
           else{
               if(s.find(pages[i])==s.end()){
                   int lru =INT_MAX;
                   int val;
                   for(auto it=s.begin();it!=s.end();it++){
                       if(index[*it]<lru){
                           lru = index[*it];
                           val=*it;
                       }
                   }
                   s.erase(val);
                   s.insert(pages[i]);
                   pf++;
               }
              index[pages[i]]=i;
           }
       }
        return pf;
    }