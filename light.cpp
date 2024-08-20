#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,k,b;
    cin>>n>>k>>b;
    bool good[n+1];
    memset(good,true,sizeof(good));
    for(int i = 0; i < b;i++) {
        int x;cin>>x;
        good[x]=false;
    }
    int count=0;
    for(int i = 1; i <= k;i++) {
         if(good[i]==true) count++;
    }
    int ans = count;
    for(int i = k+1;i <=n;i++) {
        if(good[i-k]) count--;
        if(good[i]) count++;
        ans=max(ans,count);
    }
    cout << k-ans;
    return 0;
}