#include<bits/stdc++.h>
using namespace std;
#define base 31
#define MOD 1000000009
#define ll long long
int main() {
    string s,t;
    getline(cin,s);s=' '+s;
    getline(cin,t);t=' '+t;
    ll f[s.size()];f[0]=0;
    ll hashT=0;
    for(int i = 1; i <s.size();i++) f[i]=(f[i-1]*base+s[i]-'a'+1) %MOD;
    for(int i = 1; i <t.size();i++) hashT=(hashT*base+t[i]-'a'+1)%MOD;
    for(int i = 1;i<=s.size()-t.size()+1;i++) {
        ll temp =((f[i+t.size()-2]-f[i-1]*(ll)pow(base,t.size()-1))%MOD +MOD)%MOD ;
        if(temp==hashT) cout << i << " ";
    }
    return 0;
}
// #include<bits/stdc++.h>
// using namespace std;
// #define ll long long
// #define base 31
// #define MOD 1000000006
// int main() {
//     string s,t;
//     getline(cin,s);s=' '+s;
//     getline(cin,t);t=' '+t;
//     ll f1[s.size()];
//     ll f2[t.size()];
//     f1[0]=f2[0]=0;
//     for(int i = 1;i<s.size();i++) f1[i]=(f1[i-1]*base+s[i]-'a'+1)%MOD;
//     for(int j = 1;j<t.size();j++) f2[j]=(f2[j-1]*base+t[j]-'a'+1)%MOD;
//     if(s.size()>t.size()) {
//         int len=t.size()-1;
//         while(len) {
//             if(f2[len]==((f1[s.size()-1]-f1[s.size()-1-len]*(ll)pow(base,len))%MOD+MOD)%MOD) {
//                 string res;
//                 for(int i =1;i<s.size();i++) res+=s[i];
//                 for(int i = len+1;i<t.size();i++) res+=t[i];
//                 return cout << res,0;
//             }
//             len--;
//         }
//     }else {
//         int len=s.size()-1;
//         while(len) {
//             if(((f1[s.size()-1]-f1[s.size()-1-len]*(ll)pow(base,len))%MOD+MOD)%MOD==f2[len]) {
//                 string res;
//                 for(int i =1;i<s.size();i++) res+=s[i];
//                 for(int i = len+1;i<t.size();i++) res+=t[i];
//                 return cout << res,0;
//             }
//             len--;
//         }
//     }
//     string res;
//     for(int i = 1;i<s.size();i++) res+=s[i];
//     for(int i =1;i<t.size();i++) res+=t[i];
//     cout << res;
//     return 0;
// }