//https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#

 int findPlatform(int arr[], int dep[], int n)
    {
        int res=0;
        sort(arr,arr+n);
        sort(dep,dep+n);
        int i=1;
        int j=0;
        int p=1;
        int maxi=1;
        while(i<n and j<n){
            if(arr[i]>dep[j]){
                p--;
                j++;
            }
            else{
                p++;
                i++;
                maxi=max(maxi,p);
            }
        }
        return maxi;
    }

    //prefix sum also possible o(n)