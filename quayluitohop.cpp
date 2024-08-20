#include<bits/stdc++.h>
using namespace std;
int N,a[1001],K;
void in() {
    for(int i = 1; i <=K;i++) {
        cout << a[i];
    }
    cout << endl;
}
void truy(int n) {
    for(int i = a[n-1]+1;i<= N-K+n;i++) {
        a[n]=i;
        if(n==K) in();
        else {
            truy(n+1);
        }
    }
}
int main() {
    cin >> N >> K;
    truy(1);
    return 0;
}