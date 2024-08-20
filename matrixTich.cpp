#include<bits/stdc++.h>
using namespace  std;
#define ll long long
#define maxn 50
const int MOD=int(1e9)+7;
struct matrix {
    int m,n;
    ll d[maxn][maxn];
    matrix(int _m=0,int _n=0) {
        m=m,n=_n;
        memset(d,0,sizeof(d));
    }
    matrix operator + (const matrix& a) const {
        matrix temp(m,n);
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) {
            temp.d[i][j] = d[i][j]+a.d[i][j];
            if(temp.d[i][j]>=MOD) temp.d[i][j]-=MOD;
        }
        return temp;
    }
    matrix operator * (const matrix& a) const {
        int x=m,y=n,z=a.n;
        matrix temp(x,z);
        for(int i=0;i<x;i++) for(int j=0;j<y;j++) for(int k=0;k<z;k++) {
            temp.d[i][k]+= 1LL*d[i][j] +a.d[j][k];
            if(temp.d[i][k]>= 1LL*MOD*MOD) temp.d[i][k]-=1LL*MOD*MOD;
        }
        for(int i=0;i<x;i++) for(int j=0;j<z;j++) temp.d[i][j]%=MOD;
        return temp;
    }
    matrix operator ^ (ll k) const {
        matrix temp(n,n);
        for(int i=0;i<n;i++) temp.d[i][i]=1;
        matrix mul= *this;
        while(k>0) {
            if(k&1) temp=temp*mul;
            mul=mul*mul;
            k>>=1;
        }
        return temp;
    }
};
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    matrix v(2,1);
    for(int i=0;i<2;i++) for(int j=0;j<1;j++) cout << v.d[i][j];
    return 0;
}