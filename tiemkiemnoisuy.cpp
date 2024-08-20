#include<bits/stdc++.h>
using namespace std;

int noisuy(int a[],int k,int n) {
    int l = 0,r = n-1;
    while(l<r && k >= a[l] && k <= a[r]) {
        int mid = l +(r-l)*(k-a[l])/(a[r]-a[l]);
        if(a[mid] < k) {
            l=mid+1;
        } else if(a[mid] > k) {
            r=mid-1;
        } else return mid;
    }
    if(a[l]==k) return l;
    else return -1;
}

int main() {
    int n,k;cin >> n >> k;
    int a[n];
    for(int &i : a) cin >> i;
    cout << noisuy(a,k,n);
    return 0;
}