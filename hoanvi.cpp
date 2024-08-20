#include<bits/stdc++.h>
using namespace std;
int N,a[1001];
bool check[1001];
void in() {
    for(int i = 1; i <= N;i++) {
        cout << a[i];
    }
    cout << endl;
}
void truy(int n) {
    for(int i = 1;i <=N;i++) {
        if(!check[i]) {
            a[n]=i;
            check[i]=true;
            if(n==N) in();
            else {
                truy(n+1);
            }
            check[i]=false;
        }
    }
}
int main() {
    cin >> N;
    memset(check,false,sizeof(check));
    truy(1);
    return 0;
}