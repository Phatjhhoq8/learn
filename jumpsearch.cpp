#include<bits/stdc++.h>
using namespace std;
int jumpSearch(int a[],int k,int n) {
    int i = 0;
    int d=4;
    int j = i+d;
    while(j < n && a[j] < k) {
        i=j;
        j+=d;
    }
    while(a[i] < k) {
        i++;
        if(i >=n) return -1;
    }
    if(a[i]==k) {
        return i;
    }
    return -1;
}
int main() {
    int n,k;
    cin >>n>>k;
    int a[n];
    for(int i = 0; i < n;i++) cin >> a[i];
    cout << jumpSearch(a,k,n);
    return 0;
}