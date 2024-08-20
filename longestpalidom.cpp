#include<bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cout << "Vui long nhap chuoi :";
    getline(cin, s);
    int lenght =1;
    bool F[s.size()][s.size()];
    memset(F,false,sizeof(F));
    for(int i = 0; i < s.size(); i++) F[i][i] = true;
    for(int len = 2; len <=s.size();len++){
        for(int i = 0; i < s.size()-len+1;i++){
            int j = i + len-1;
            if(len == 2 && s[i]==s[j]) {
                F[i][j] = true;
            } 
            if(F[i+1][j-1] == true && s[i]==s[j]) {
                F[i][j] = true;
            }
            if(F[i][j]) lenght = max(len,lenght);
        }
    }
    cout << "\n dap an :"<< lenght;
    return 0;
}