#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << " Vui long nhap so luong dinh :";
    cin >> n;
    vector<pair<int, int>> dsc;
    int a[n+1][n+1];
    for(int i = 1; i <=n;i++) {
        for(int j=1; j <=n ;j++){
            cin >> a[i][j];
        }
    }
    for(int i= 1; i<= n; i++) {
        for(int j =1; j <= n; j++) {
            if(a[i][j] == 1 && i <= j) {
                dsc.push_back({i,j});
            }
        }
    }
    for(auto x : dsc) {
        cout << x.first << " " << x.second << endl;
    }
    return 0;
}