#include<bits/stdc++.h>
using namespace std;

vector<int> a[1001];
bool check[1001];
void input() {
    int n,m;
    cout << "Vui long nhap so luong dinh va so luong canh :";
    cin >> n >> m;
    for(int i = 1; i <= m;i++) {
        int x,y;cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    memset(check,false,sizeof(check));
}
void DFS(int u) {
    cout << u << " ";
    check[u] = true;
    for(int x : a[u]) {
        if(!check[x]) DFS(x);
    }
}
int main() {
    input();
    DFS(1);
    return 0;
}