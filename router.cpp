#include<bits/stdc++.h>
using namespace std;

vector<int > a[1001];
bool check[1001];
int parent[1001];

void DFS(int n) {
    check[n]=true;
    for(int x : a[n]) {
        if(!check[x]) {
            parent[x] = n;
            DFS(x);
        }
    }
}
void path(int st,int en) {
    DFS(st);
    if(!check[en]) {
        cout << "Khong ton tai duong di tu " << st << " den " << en;
    } else{
        vector<int> pth;
        while(en!=st) {
            pth.push_back(en);
            en = parent[en];
        }
        pth.push_back(st);
        reverse(pth.begin(),pth.end());
        for(int x : pth) {
            cout << x << " ";
        }
    }
}
int main() {
    int n,m,st,en;
    cout << "Vui long nhap so luong dinh va so luong canh :";
    cin >> n >> m;
    for(int i = 1; i<=m;i++) {
        int x,y;cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    memset(check,false,sizeof(check));
    memset(parent,0,sizeof(parent));
    cout << "Vui long nhap duong di can tim tu A den B";
    cin >> st >> en;
    path(st,en);
    return 0;
}