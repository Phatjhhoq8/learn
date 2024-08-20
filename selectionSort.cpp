#include<bits/stdc++.h>
using namespace std;

void selectionSort(int a[],int n) {
    for(int i = 0; i < n-1;i++) {
        int i_min=i;
        for(int j = i;j<n;j++) {
            if(a[j] < a[i_min]) {
                i_min=j;
            }
        }
        int temp = a[i_min];
        a[i_min]=a[i];
        a[i]=temp;
    }
}

int main() {
    int n;cin >> n;
    int a[n];
    for(int &x:a) cin >> x;
    selectionSort(a,n);
    for(int x: a) cout << x << " ";
    return 0;
}