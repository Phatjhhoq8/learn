#include<bits/stdc++.h>
using namespace std;
void heapify(int a[],int n,int i) {
    int lagest = i;
    int left = 2*i+1;
    int right = 2*i+2;
    if(left < n && a[left]>a[lagest]) lagest=left;
    if(right < n && a[right]>a[lagest]) lagest=right;
    if(lagest !=i) {
        swap(a[i],a[lagest]);
        heapify(a,n,lagest);
    }
}
void heapSort(int a[],int n) {
    for(int i=n/2-1;i>=0;i--) {
        heapify(a,n,i);
    }
    for(int i=n-1;i>=0;i--) {
        swap(a[i],a[0]);
        heapify(a,i,0);
    }
}
int main() {
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    heapSort(a,n);
    for(int i=0;i<n;i++) cout << a[i] << " ";
    return 0;
}