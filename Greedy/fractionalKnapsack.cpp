//https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#


    static bool comp(Item i1,Item i2){
        double i1s = (double)(i1.value)/(double)(i1.weight);
        double i2s = (double)(i2.value)/(double)(i2.weight);
        return i1s>i2s;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr,arr+n,comp);
        double res=0;
        for(int i=0;i<n;i++){
            if(arr[i].weight<W){
                W=W-arr[i].weight;
                res+=arr[i].value;
            }
            else{
                res+= (double)(arr[i].value)/(double)(arr[i].weight) * W;
                break;
            }
        }
        return res;
    }