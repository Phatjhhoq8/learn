#include<bits/stdc++.h>
using namespace std;

struct garph {
    int u,v,w;
};
int n,m;
int parent[1001];
int sz[1001];
vector<garph> canh;

void input() {
    cout <<"Vui long nhap so luong canh va so luong dinh :";
    cin >> n >> m;
    for(int i = 1; i<= m ; i++) {
        garph e;
        int x,y,z;cin >> x >> y >> z;
        e.u = x;e.v=y;e.w=z;
        canh.push_back(e);
    }
}
void make_set() {
    for(int i = 1; i<=n;i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}
int find(int u) {
    if(u == parent[u]) return u;
    return parent[u] = find(parent[u]);
}
bool Union(int a,int b) {
    a=find(a);b=find(b);
    if(a==b) return false;
    if(sz[a] < sz[b]) swap(a,b);
    parent[b]=a;
    sz[a] += sz[b];
    return true;
}
bool cmp(garph a,garph b) {
    return a.w < b.w;
}
void kruskal() {
    vector<garph> krus;
    int d = 0;
    sort(canh.begin(),canh.end(),cmp);
    for(int i = 0 ; i < m;i++) {
        if(krus.size() == n-1) break;
        garph e = canh[i];
        if(Union(e.u,e.v)) {
            krus.push_back(e);
            d += e.w;
        }
    }
    if(krus.size() != n-1) {
        cout <<"Do thi khong lien thong ";
    }else {
        cout << "\nMST: " << d << endl;
        for(auto x : krus) {
            cout << x.u << " " << x.v << " " <<  x.w << endl;
        }
    }
}
int main() {
    input();
    make_set();
    kruskal();
    return 0;
}