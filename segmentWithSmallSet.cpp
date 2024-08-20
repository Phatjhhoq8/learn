#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;cin >> n >>m;
    int a[n];
    for(int& x : a) cin >> x;
    int l=0,r=0;
    int dem[100001];
    memset(dem,0,sizeof(dem));
    int cnt = 0;
    int res = 0;
    while(r < n) {
        dem[a[r]]++;
        if(dem[a[r]] == 1) cnt++;
        while(cnt > m) {
            if(dem[a[l]]==1)cnt--;
            dem[a[l]]--;
            l++;
        }
        res+=r-l+1;
        r++;
    }
    cout << res;
    return 0;
}