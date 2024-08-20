#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;cin>>n>>m;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second=i;
    }
    sort(a.begin(),a.end());
    int i = 0;
    int j = n-1;
    while(i<j) {
        if(a[i].first + a[j].first > m) j--;
        if(a[i].first+ a[j].first < m) i++;
        if(a[i].first + a[j].first == m) {
            cout << a[i].second << " " << a[j].second;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}