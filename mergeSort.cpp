#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int mid,int r) {
    int a_left[mid-l+1];
    int a_right[r-mid];
    for(int i = 0; i < mid-l+1;i++) {
        a_left[i]=a[l+i];
    }
    for(int i = 0; i <r-mid;i++) {
        a_right[i]=a[mid+1+i];
    }
    int i1=0,i2=0;
    int k = l;
    while(i1<(mid-l+1) && i2 <(r-mid)) {
        if(a_left[i1] <= a_right[i2]) {
            a[k]=a_left[i1];
            i1++;
        }else {
            a[k]=a_right[i2];
            i2++;
        }
        k++;
    }
    while(i1<(mid-l+1)) {
        a[k]=a_left[i1];
        i1++;k++;
    }
    while(i2 <(r-mid)) {
        a[k]=a_right[i2];
        i2++;k++;
    }
}
void mergeSort(int a[],int l,int r) {
    if(l < r) {
        int mid = (l+r)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);

        merge(a,l,mid,r);
    }
}
int main() {
    int n;cin>>n;
    int a[n];
    for(int &x : a) cin >> x;
    int l=0,r=n-1;
    mergeSort(a,l,r);
    for(int x : a) cout << x << " ";
    return 0;
}