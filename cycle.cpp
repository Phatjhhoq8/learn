#include<bits/stdc++.h>
using namespace std;

int n,m,st,en;
vector<int> a[1001];
bool check[1001];
int color[1001];
int parent[1001];
int in[1001];

void inputVoHuong() {
    cout <<"Vui long nhap so luong dinh va so luong canh :";cin >> n >> m;
    for(int i = 1;i<=m;i++) {
        int x,y;cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);

    }
    memset(check,false,sizeof(check));
}
void inputCoHuong() {
    cout <<"Vui long nhap so luong dinh va so luong canh :";cin >> n >> m;
    for(int i = 1;i<=m;i++) {
        int x,y;cin >> x >> y;
        a[x].push_back(y);
        in[y]++;
    }
    memset(color,0,sizeof(color));
}
bool dfsVoHuong(int u) {
    check[u] = true;
    for(int x : a[u]) {
        if(!check[x]) {
            parent[x]=u;
            if(dfsVoHuong(x)) return true;
        } else if(x != parent[u]) {
            st= x;
            en=u;
            return true;
        }
    }
    return false;
}

bool bfsVoHuong(int u) {
    queue<int> q;
    q.push(u);
    check[u] =true;
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(int x : a[v]) {
            if(!check[x]) {
                q.push(x);
                check[x]=true;
                parent[x]=v;
            } else if(x != parent[v]) {
                return true;
            }
        }
    }
    return false;
}
bool dfsCoHuong(int u) {
    color[u] = 1;
    for(int x : a[u]) {
        if(color[x] == 0) {
            parent[x]=u;
            if(dfsCoHuong(x)) return true;
        } else if(color[x] == 1) {
            return true;
        }
    }
    color[u]=2;
    return false;
}

bool bfsCoHuong() {
    queue<int> q;
    int count = 0;
    for(int i = 1; i<=n;i++) {
        if(in[i]==0) {
            q.push(i);
        }
    }
    while(!q.empty()) {
        int v = q.front();q.pop();
        count++;
        for(int x : a[v]) {
            in[x]--;
            if(in[x]==0) {
                q.push(x);
            }
        }
    }
    return count == n;
}

int main() {
    inputCoHuong();
    if(!bfsCoHuong()) {
        cout <<"Yes";
    } else {
        cout <<"No";
    }
    return 0;
}