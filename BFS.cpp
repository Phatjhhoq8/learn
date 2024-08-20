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
void BFS(int n) {
    queue<int> q;
    q.push(n);
    check[n] = true;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for(int x : a[v]) {
            if(!check[x]) {
                q.push(x);
                check[x]= true;
            }
        }
    }
}

int main() {
    input();
    BFS(1);
    return 0;
}