#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> a[1001];
bool check[1001];
stack<int > topo;

void input() {
    cout <<"Vui long nhap so luong dinh va so luong canh:";cin >> n >> m;
    for(int i = 0; i< m; i++) {
        int x,y;cin >> x >> y;
        a[x].push_back(y);
    }
    memset(check,false,sizeof(check));
}
void DFS(int u) {
    check[u]=true;
    for(int x: a[u]) {
        if(!check[x]) {
            DFS(x);
        }
    }
    topo.push(u);
}
int main() {
    input();
    for(int i = 1; i<= n; i++) {
        if(!check[i]) DFS(i);
    }
    while(!topo.empty()) {
        cout << topo.top() << " ";
        topo.pop();
    }
    return 0;
}