#include<bits/stdc++.h>
using namespace std;

bool check(int n,int k,int arr[]) {
    set<int> s;
    for(int i = 0; i < k; i++) {
        if(s.count(arr[i])) return true;
        s.insert(arr[i]);
    }
    for(int i = k ; i < n; i++) {
        s.erase(arr[i-k]);
        if(s.count(arr[i])) return true;
        s.insert(arr[i]);
    }
    return false;
}
int main() {
    int n,k;cin>>n>>k;
    int arr[n];
    for(int i = 0;i<n;i++) cin>>arr[i];
    if(check(n,k,arr)) {
        cout << "Yes";
    }else {
        cout << "No";
    }
    return 0;
}