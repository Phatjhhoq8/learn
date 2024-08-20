#include<bits/stdc++.h>
using namespace std;
int N;
int cnt = 0;
int a[1001][1001];
int dx[]={-2,-2,-1,-1,1,1,2,2};
int dy[]={-1,1,-2,2,-2,2,-1,1};

void in() {
    for(int i = 1; i<=N;i++) {
        for(int j = 1; j <=N;j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

void truy(int x,int y) {
    cnt++;
    a[x][y]=cnt;
    if(cnt==N*N) {
        in();
        exit(0);
    }
    for(int i = 0 ; i < 8;i++) {
        int x1=x+dx[i];
        int y1=y+dy[i];
        if(x1 >=1 && x1 <= N && y1 >= 1 && y1 <= N && a[x1][y1] == 0) {
            truy(x1,y1);
        } 
    }
    cnt--;
    a[x][y]=0;
}
int main() {
    cin >> N;
    int x,y;cin>>x>>y;
    memset(a,0,sizeof(a));
    truy(x,y);
    return 0;
}