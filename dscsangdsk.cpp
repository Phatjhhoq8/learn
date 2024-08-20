#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,m;
    cout << "Vui long nhap so luong dinh va so luong canh: ";
    cin >> n >> m;
    vector<int> a[n+1];
    for(int i = 1;i <=m ;i++) {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    for(int i = 1; i <=n; i++) {
        cout << i << " : ";
        for(int x: a[i]) {
            cout << x << " ";
        }
        cout << endl;
    }
    return 0;
}