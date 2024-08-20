#include<bits/stdc++.h>
using namespace std;
struct canh {
    int x,y,w;
};

int n,m;
vector<pair<int,int>> adj[1001];
bool used[1001];
int parent[1001],d[1001];

void input() {
    cout <<"Vui long nhap so luong canh va so luong dinh :";cin >> n >> m;
    for(int i = 1; i<=m ; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    memset(used,false,sizeof(used));
    for(int i = 1;i <=n ;i++) d[i]=INT_MAX;
}

void prim(int u) {
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    int res = 0;
    vector<canh> MST;
    q.push({0,u});
    while(!q.empty()) {
        pair<int,int> top = q.top();q.pop();
        int dinh = top.second,trongso=top.first;
        if(used[dinh]) continue;
        res+=trongso;
        used[dinh] =true;
        if(u != dinh) {
            MST.push_back({dinh,parent[dinh],trongso});
        }
        for(auto x : adj[dinh]) {
            if(!used[x.first] && x.second < d[x.first]) {
                q.push({x.second,x.first});
                parent[x.first] = dinh;
                d[x.first] = x.second;
            }
        }
    }
    cout << "\nMST : " << res;
    for(auto it : MST) {
        cout << "\n" << it.x << " " << it.y << " " << it.w;
    }
}

int main() {
    input();
    prim(6);
    return 0;
}