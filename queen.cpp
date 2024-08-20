#include<bits/stdc++.h>
using namespace std;
bool cot[10001],d1[10001],d2[10001];
int X[10001];
int N;
int a[10001][10001];
int cnt = 0;
void in() {
    for(int i = 1; i <=N;i++) {
        a[i][X[i]]=1;
    }
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cout << a[i][j];
        }
        cout << endl;
    }
}
void truy(int n) {
    for(int i = 1; i <= N;i++) {
        if(!cot[i] && !d1[n-i+N] && !d2[n+i-1]) {
            X[n]=i;
            cot[i]=d1[n-i+N]=d2[n+i-1] = true;
            if(n==N) cnt++;
            else truy(n+1);
            cot[i]=d1[n-i+N]=d2[n+i-1] = false;
        }
    }
}
int main() {
    memset(cot,false,sizeof(cot));
    memset(d1,false,sizeof(d1));
    memset(d2,false,sizeof(d2));
    memset(a,0,sizeof(a));
    cin >> N;
    truy(1);
    cout << cnt;
    return 0;
}