#include<bits/stdc++.h>
using namespace std;
int g,x,y;
int phi[1000];

void extended_euclid(int a,int b) {
    if(b==0) {
        x=1;y=0;g=a;
        // cout << x << " " << y << " " << a << " " << b << " " << endl;
    } else {
        extended_euclid(b,a%b);
        int temp = x;
        x=y;
        y=temp-a/b*y;
        // cout << x << " " << y << " " << a << " " << b << " " << endl;
    }
}
int module_inverse(int a,int b) {
    extended_euclid(a,b);
    if(g!=1) return -1;
    return (x%b+b) %b;
}
int power(int a,int b,int M) {
    if(b==0) return 1;
    if(b==1) return a;
    int half = power(a,b/2,M);
    if(b&1) { 
        return ((half*half)%M * a)%M;
    } else return (half*half) %M;
}
int module_inverse2(int a,int M) {
    return power(a,M-2,M);
}
int module_divide(int a,int b,int c) {
    int inverse = module_inverse(b,c);
    return (a%c *inverse) %c;
}
int find_m_order(int a,int b) {
    int mul = 1;
    for(int i = 1; i <=b;i++) {
        mul=(mul*a)%b;
        if(mul == 1) return i;
    }
}
bool check_quadratic_residue(int N,int P) {
    if(P==2) return true;
    return (power(N,(P-1)/2,P)==1);
}
int check_quadratic_residue2(int N,int P) { 
    if(N%4!=3||P%4!=3) return -1;
    int x = power(N,(P+1)/2,P);
    if((x*x)%P==N%P) return x;
    x=P-x;
    if((x*x)%P==N%P) return x;
    return -1;
}
void sang() {
    for(int i = 1; i <= 1000;i++) phi[i]=i;
    for(int i = 2; i <=1000;i++) {
        if(phi[i]==i) {
            for(int j = i;j <=1000;j+=i) {
                phi[j]-=phi[j]/i;
            }
        }
    }
}
int _phi(int n) {
    int ans = n;
    for(int i =2;i*i<=n;i++) {
        if(n%i==0) {
            ans-=ans/i;
            while(n%i==0) n/=i;
        }
    }
    if(n!=1) ans-=ans/n;
    return ans;
}
int main() {
    sang();
    for(int i = 1; i<=100;i++) {
        cout << phi[i] <<  " ";
    }
    cout << endl << _phi(5);
    return 0;
}