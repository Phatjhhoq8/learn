#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<int> a[1001];
int in[1001]={0};

void input() {
    cout <<"Vui long nhap so luong dinh va so luong canh:";cin >> n >> m;
    for(int i = 0; i< m; i++) {
        int x,y;cin >> x >> y;
        a[x].push_back(y);
        in[y]++;
    }
}
void kahn() {
    queue<int> q;
    for(int i = 1; i <= n; i++) {
        if(in[i]==0) q.push(i);
    }
    while(!q.empty()) {
        int v = q.front();
        cout << v << " ";
        q.pop();
        for(int x : a[v]) {
            in[x]--;
            if(in[x]== 0 ) {
                q.push(x);
            }
        }
    }
}
int main() {
    input();
    kahn();
    return 0;
}