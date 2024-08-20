#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;cin >> n >> m;
    int a[n];
    for(int &x : a) cin >> x;
    multiset<long long> s;
    int l=0,r=0;
    int res = 0;
    while(r < n) {
        s.insert(a[r]);
        while((*s.rbegin()-*s.begin()) > m) {
            auto it = s.find(a[l]);
            s.erase(it);
            l++;
        }
        res+= r-l+1;
        r++;
    }
    cout << res;
    return 0;
}