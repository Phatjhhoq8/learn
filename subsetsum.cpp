#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,S;
    cout << "Vui long nhap so luong phan tu cua mang va tong muon xet :";
    cin >> n >> S;
    int a[n];
    for(int i = 0; i <n; i++) cin >> a[i];
    bool can[S+1];
    memset(can,false,sizeof(can));
    can[0]=true;
    for(int i = 0; i < n;i++) {
        for(int j = S; j >= a[i];j--) {
            if(can[j-a[i]]) can[j]= true;
        }
    }
    if(can[S]==true) cout << "yes";
        else cout << "No";
    return 0;
}