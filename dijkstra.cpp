#include<bits/stdc++.h>
using namespace std;

int n,m,s;
vector<pair<int,int>> adj[1001];
int d[1001];

void input() {
    cout <<"Vui long nhap so luong dinh va so luong canh va vi tri bat dau :";cin >> n >> m >> s;
    for(int i = 1; i<= m ; i++) {
        int x,y,z;cin >> x >> y >> z;
        adj[x].push_back({y,z});
    }
    for(int i = 1; i <= n; i++) d[i] =1e9;
}
void dijkstra(int u) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    d[u] = 0;
    q.push({0,u});
    while(!q.empty()) {
        pair<int,int> v = q.top();q.pop();
        if(v.first > d[v.second]) continue;
        for(auto x : adj[v.second]) {
            if(d[x.first] > x.second +d[v.second]) {
                d[x.first] = x.second +d[v.second];
                q.push({d[x.first],x.first});
            }
        }
    }
    for(int i = 1; i <= n; i++) cout << d[i] << " ";
}
int main() {
    input();
    dijkstra(s);
    return 0;
}