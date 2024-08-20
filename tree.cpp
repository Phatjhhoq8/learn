#include<bits/stdc++.h>
using namespace std;

struct queues{
    int u,v,w;
};

vector<queues> canh;
vector<queues> qu;
pair<int,int> parent[100];

int path(int x,int y) {
    int d = 0;
    while(y!=x) {
        d+= parent[y].second;
        if(parent[y].first == parent[x].first) {
            d+=parent[x].second;
            x=parent[x].first;
        }
        y=parent[y].first;
    }
    return d;
}
int main() {
    int n;cin >> n;//số lượng đỉnh
    for(int i = 1;i<n;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        parent[y]= {x,z};
        canh.push_back({x,y,z});
    }
    int m;cin >> m;//số lượng queue
    for(int i = 1; i<=m;i++) {
        int x,y,z;
        cin >> x >> y >> z;
        qu.push_back({x,y,z});
    }
    for(int i = 1; i <= m; i++) {
        if(qu[i-1].u == 1) {
            parent[canh[qu[i-1].v-1].v].second=qu[i-1].w;
            
        }else if(qu[i-1].u==2) {
            cout << path(qu[i-1].v, qu[i-1].w) << endl;
        }
    }
    return 0;
}