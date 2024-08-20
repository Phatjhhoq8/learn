#include<bits/stdc++.h>
using namespace std;

int n,m;
char a[1001][1001];
int dx[] ={1,0,0,-1};
int dy[]={0,-1,1,0};
int dp[1001][1001];
void input() {
    cout << "Vui long nhap so luong dinh va so luong canh: ";cin >> n >> m;
    for(int i =1; i<=n;i++) {
        for(int j = 1; j <=m;j++) {
            cin >> a[i][j];
        }
    }
    memset(dp,0,sizeof(dp));
}
void DFS(int i,int j) {
    if(a[i][j] == 'B') return;
    a[i][j] ='x';
    for(int k = 0; k < 4; k++) {
        int i1 = i + dy[k];
        int j1 = j + dx[k];
        if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'o' || a[i1][j1] =='B') {
            dp[i1][j1] = dp[i][j] + 1;
            a[i1][j1]='x';
            DFS(i1,j1);
        }
    }
}
void BFS(int i,int j) {
    queue<pair<int ,int>>q;
    q.push({i,j});
    a[i][j]='x';
    while(!q.empty()) {
        pair<int ,int> v = q.front();
        q.pop();
        for(int k = 0; k <4; k++) {
            int i1 = v.first + dy[k];
            int j1 = v.second + dx[k];
            if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1]!='x'){
                dp[i1][j1] = dp[v.first][v.second]+1;
                if(a[i1][j1] == 'B') return;
                q.push({i1,j1});
                a[i1][j1]='x';
            }
        }
    }
}

int main() {
    input();
    int x,y,z,t;
    for(int i = 1; i<= n; i++) {
        for(int j = 1; j<=m; j++) {
            if(a[i][j] == 'A') {
                x=i;
                y=j;
            }
            if(a[i][j] == 'B') {
                z=i;
                t=j;
            }
        }
    }
    BFS(x,y);
    if(dp[z][t] == 0) {
        cout << "Khong co duong di";
    } else{
        cout << "Duong di can " << dp[z][t];
    }
    return 0;
}