#include<bits/stdc++.h>
using namespace std;

void insertionSort(int a[],int n) {
    for(int i = 1;i < n; i++) {
        int j = i;
        while(j > 0 && a[j] < a[j-1]) {
            int temp = a[j];
            a[j] = a[j-1];
            a[j-1]=temp;
            j--;
        }
    }
}
void insertion_sort(int a[],int n) {
    for(int i = 1;i < n; i++) {
        int j = i-1;
        int key = a[i];
        while(j >= 0 && a[j] > key) {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=key;
    }
}
int main() {
    int n;cin>>n;
    int a[n];
    for(int &i : a) cin >> i;
    insertion_sort(a,n);
    for(int x : a) cout << x << " ";
    return 0;
}