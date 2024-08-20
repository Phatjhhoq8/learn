#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> adj[1001],r_adj[1001];
bool check[1001];
stack<int> st;

void input() {
    cout <<"Vui long nhap so luong dinh va so luong canh: "; cin >> n >> m;
    for(int i = 1; i<= m ; i++) {
        int x,y;
        cin >> x >> y;
        adj[x].push_back(y);
        r_adj[y].push_back(x);
    }
}
void DFS1(int u) {
    check[u]=true;
    for(int x: adj[u]) {
        if(!check[x]) {
            DFS1(x);
        }
    }
    cout << u << " ";
    st.push(u);
}
void DFS2(int u) {
    check[u]=true;
    for(int x : r_adj[u]) {
        if(!check[x]) {
            DFS2(x);
        }
    }
    cout << u << " ";
}
void SCC() {
    input();
    memset(check,false,sizeof(check));
    for(int i = 1;i<=n;i++) {
        if(!check[i]) DFS1(i);
    }
    cout << endl;
    memset(check,false,sizeof(check));
    int count = 0;
    while(!st.empty() ) {
        int v = st.top();st.pop();
        if(!check[v]) {
            DFS2(v);
            count++;
        }
    }
    cout <<"\nSo thanh phan lien thong manh la :" << count;
}
int main() {
    SCC();
    return 0;
}