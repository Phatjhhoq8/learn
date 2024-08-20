#include<bits/stdc++.h>
using namespace std;

int binarySearch(int a[],int k,int n) {
    int l = 0,r=n-1;
    while(l!=r) {
        int mid = (l+r)/2;
        if(a[mid]==k) return mid;
        if(a[mid] > k) {
            r=mid-1;
        }
        if(a[mid] < k) {
            l=mid+1;
        }
    }
    if(a[l]==k) return l;
    return -1;
}
int binary_search(int a[],int k,int l,int r)  {
    if(l==r) {
        if(a[l]==k) return l;
        else return -1;
    }
    int mid = (l+r)/2;
    if(a[mid]==k) return mid;
    if(a[mid] > k) {
            return binary_search(a,k,l,mid-1);
        }
        if(a[mid] < k) {
            return binary_search(a,k,mid+1,r);
        }
}
int main() {
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int &i : a) cin>>i;
    int l=0,r=n-1;
    cout << binary_search(a,k,l,r);
    return 0;
}