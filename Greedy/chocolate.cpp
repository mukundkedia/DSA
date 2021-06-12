//https://www.spoj.com/problems/CHOCOLA/

#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int x[1003], y[1003];

int main(){
        int m,n;
        cin >> m >> n;
        for(int i=1;i<m;++i){
            cin >> x[i];
        }
        for(int i=1;i<n;++i){
            cin >> y[i];
        }
        int h = 1,v=1;
        sort(x+1,x+m);
        reverse(x+1,x+m);
        sort(y+1,y+n);
        reverse(y+1,y+n);
        int i=1,j=1;
        int ans = 0;
        while(i<m && j<n){
            if(x[i] > y[j]){
                ans += x[i]*v;
                ++h;
                ++i;
            } else {
                ans += y[j]*h;
                ++v;
                ++j;
            }
        }
        if(i<m){
            int sum = 0;
            while(i<m){
                sum += x[i];
                ++i;
            }
            ans += sum*v;
        } else {
            int sum = 0;
            while(j<n){
                sum += y[j];
                ++j;
            }
            ans += sum*h;
        }
        cout << ans << endl;
    return 0;
}