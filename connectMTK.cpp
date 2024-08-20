#include<bits/stdc++.h>
using namespace std;

int n,m;
char a[1001][1001];
int dx[4]= {0,1,0,-1};
int dy[4] = {-1,0,1,0};

void DFS(int i,int j) {
    a[i][j] = 'o';
    for(int k = 0; k <4;k++) {
        int i1 = i + dy[k];
        int j1 = j + dx[k];
        if(i1 >= 1 && i1 <=n && j1 >=1 && j1 <= m && a[i1][j1] == 'x') {
            DFS(i1,j1);
        }
    }

}
void BFS(int i,int j) {
    queue<pair<int,int>> q;
    q.push({i,j});
    a[i][j]='o';
    while(!q.empty()) {
        pair<int, int> v = q.front();
        q.pop();
        for(int k =0;k<4;k++) {
            int i1 = v.first + dy[k];
            int j1 = v.second+dx[k];
            if(i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] == 'x') {
                q.push({i1,j1});
                a[i1][j1] = 'o';
            }
        }
    }
}

int main() {
    cout << "Vui long nhap so luong dinh va so luong canh : ";cin >> n >> m;
    for(int i = 1; i<=n;i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int count= 0;
    cout << "So luong thanh phan lien thong la :";
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j <=m ;j++) {
            if(a[i][j] == 'x') {
                ++count;
                BFS(i,j);
            }
        }
    }
    cout << count;
    return 0;
}