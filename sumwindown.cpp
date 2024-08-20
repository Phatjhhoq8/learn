#include<bits/stdc++.h>
using namespace std;
bool check() {
    int n,k,m;cin>>n>>k>>m;
    int a[n];
    set<int> s;
    for(int i = 0; i < n; i++) cin>>a[i];
    for(int i = 0; i < k;i++) {
        if(s.count(a[i])) return true;
        auto it = s.lower_bound(a[i]-m);
        if(it != s.end() && *it <= a[i]+m) return true;
        s.insert(a[i]);
    }
    for(int i = k; i < n; i++) {
        s.erase(a[i-k]);
        if(s.count(a[i])) return true;
        auto it = s.lower_bound(a[i]-m);
        if(it != s.end() && *it <= a[i]+m) return true;
        s.insert(a[i]);
    }
    return false;
}
int main() {
    if(check()) cout <<"Yes";
    else cout << "No";

    return 0;
}