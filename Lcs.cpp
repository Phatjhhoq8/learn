#include<bits/stdc++.h>
#include<string>
using namespace std;

int main() {
    string a,b;
    cout << "Vui long nhap chuoi 1 :";
    getline(cin,a);
    cout << "Vui long nhap chuoi 2 :";
    getline(cin,b);
    int dp[a.size()+1][b.size()+1];
    for(int i = 0; i <= a.size();i++) {
        for(int j = 0; j<= b.size();j++) {
            if(i== 0 || j == 0) dp[i][j] = 0;
            else if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else if(a[i-1]!=b[j-1]) dp[i][j] = max(dp[i-1][j],dp[i][j-1]);

        }
    }
    cout << "\n Dap an :" << dp[a.size()][b.size()];
    return 0;
}