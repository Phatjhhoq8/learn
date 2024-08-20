#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s,t;
vector<ll> z_array(string x) {
    vector<ll>z(x.size());
    ll l=0,r=0;
    for(int i =1;i<x.size();i++) {
        z[i]=max((ll)0,(ll)min(z[i-l],(ll)(r-i+1)));
        while(i+z[i]<x.size() &&  x[z[i]]==x[i+z[i]]) {
            l=i;r=z[i]+i;z[i]++;
        }
    }
    return z;
}
int main() {
    getline(cin,s);
    getline(cin,t);
    string x=t+'#'+s;
    vector<ll> z=z_array(x);
    ll ans =0;
    for(int i =t.size()+1;i<x.size();i++) {
        if(ans<z[i] && i+z[i]==x.size())ans=z[i];
    }
    for(int i = 0; i <s.size();i++) cout << s[i];
    for(int i= ans;i<t.size();i++) cout <<t[i];
    return 0;
}