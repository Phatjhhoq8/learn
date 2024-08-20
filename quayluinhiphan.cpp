#include<bits/stdc++.h>
using namespace std;
int N;
int a[1001];
void in() {
    for(int i = 1; i <= N;i++) {
        cout << a[i];
    }
    cout << endl;
}
void try(int n) {
    for(int i = 0; i <=1;i++) {
        a[n]=i;
        if(n==N) in();
        else {
            try(n+1);
        }
    }
}
int main() {
    cin >> N;
    try(1);
    return 0;
}