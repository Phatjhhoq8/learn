#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << " Vui long nhap so luong dinh : ";
    cin >> n;cin.ignore();
    vector<pair<int,int>> res[n+1];
    for(int i = 1;i<= n; i++) {
        string s,num;
        getline(cin,s);
        stringstream ss(s);
        while(ss >> num) {
            if(i < stoi(num)) res[i].push_back({i,stoi(num)});
        }
    }
    for(int i = 1;i <=n;i++) {
        for(auto x : res[i]) cout << x.first << " " << x.second << endl;
    }
    return 0;
}