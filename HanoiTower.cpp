#include<iostream>
using namespace std;

void chuyen(int n,char a,char b){
    cout << "Chuyen thap thu " << n << " tu " << a << " den " << b << endl;
}
void HaNoiTower(int n, char a,char b, char c) {
    if (n==1) {
        chuyen(n,a,c);
    } else {
        HaNoiTower(n-1,a,c,b);
        chuyen(n,a,c);
        HaNoiTower(n-1,b,a,c);
    }
}
int main() {
    int n; 
    cout << "Vui long nhap so luong thap " << endl;
    cin >> n;
    char A = 'A';
    char B = 'B';
    char C = 'C';
    HaNoiTower(n,A,B,C);
    return 0;
}