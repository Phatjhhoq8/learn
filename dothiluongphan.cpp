#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> a[1001];
int color[1001];

void input() {
    cout <<"Vui long nhap so luong dinh va so luong canh: "; cin >> n >> m;
    for(int i = 1;i<= m ; i++) {
        int x, y;cin >>x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    memset(color,-1,sizeof(color));
}
bool dfs(int u,int par) {
    color[u]=1-color[par];
    for(int x : a[u]) {
        if(color[x] == -1) {
            if(!dfs(x,u)) return false;
        } else if(color[x] == color[u]) return false;
    }
    return true;
}
bool bfs(int u) {
    queue<int > q;
    q.push(u);
    color[u] = 0;
    while(!q.empty()) {
        int v = q.front();q.pop();
        for(int x: a[v] ) {
            if(color[x] == -1) {
                color[x]= 1-color[v];
                q.push(x);
            } else if(color[x]==color[v]) return false;
        }
    }
    return true;
}
int main() {
    input();
    color[0]=0;
    if(bfs(1)) cout << "Yes";
    else cout << "No";
    return 0;
}