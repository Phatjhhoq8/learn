#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Vui long nhap so luong dinh :";cin >> n;
    int a[n+1][n+1];
    vector<int> res[n+1];
    for(int i = 1; i<=n;i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j <= n; j++) {
            if(a[i][j]) {
                res[i-1].push_back(j);
            }
        }
    }
    for(int i = 0;i < n;i++) {
        cout << i + 1 << " :";
        for(int x : res[i]) cout << x << " ";
        cout << endl;
    }
    return 0;
}