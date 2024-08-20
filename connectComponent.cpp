#include<bits/stdc++.h>
using namespace std;

vector<int> a[1001];
bool check[1001];
int n,m;

void inpt() {
    cout << "Vui long nhap so luong dinh va so luong canh :";cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x,y; cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    memset(check, false,sizeof(check));
}
void DFS(int u) {
    cout << u << " ";
    check[u] = true;
    for(int x : a[u]) {
        if(!check[x]) {
            DFS(x);
        }
    }
}
void BFS(int u) {
    queue<int> q;
    q.push(u);
    check[u] = true;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int x : a[v]) {
            if(!check[x]) {
                q.push(x);
                check[x] = true;
            }
        }
    }
}
int connectComponent() {
    int count = 0;
    for(int i = 1; i<= n; i++) {
        if(!check[i]) {
            cout << "Thanh phan lien thong thu " << i << " la: ";
            count++;
            DFS(i);
            cout << endl;
        }
    }
    return count;
}
int main() {
    inpt();
    cout << "So thanh phan lien thong la " << connectComponent();
    
    return 0;
}