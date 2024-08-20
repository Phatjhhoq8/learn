#include<bits/stdc++.h>
using namespace std;
void swap(int a[],int l,int r) {
    int temp=a[l];
    a[l]=a[r];
    a[r]=temp;
}
int partition(int a[],int l,int r) {
    int pivot = a[l];
    int cnt=0;
    for(int i =l+1; i <= r;i++) {
        if(a[i]<= pivot) cnt++;
    }
    int indexPivot = l+cnt;
    swap(a,l,indexPivot);
    while(l < indexPivot && r > indexPivot) {
        while(a[l] <= pivot) l++;
        while(a[r] > pivot) r--;
        if(l < indexPivot && r > indexPivot) swap(a,l,r);
    }
    return indexPivot;
}

void quickSort(int a[],int l,int r) {
    if(l<r) {
        int pivot = partition(a,l,r);
        quickSort(a,l,pivot-1);
        quickSort(a,pivot+1,r);
    }
}

int main() {
    int n;cin>>n;
    int a[n];
    for(int &x : a) cin >> x;
    int l=0,r=n-1;
    quickSort(a,l,r);
    for(int x : a) cout << x << " ";
    return 0;
}