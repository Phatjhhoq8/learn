#include<bits/stdc++.h>
using namespace std;

int parent[1001];
int size[1001];
int n;

void make_set() {
    for(int i = 1; i <=n;i++) {
        parent[i]=i;
        size[i]=1;
    }
}
int find(int u) {
    if(u==parent[u]) return u;
    else{
        return parent[u] = find(parent[u]);
    }
}
void union(int a,int b) {
    a = find(a);b=find(b);
    if(size[a] < size[b]) swap(a,b);
    parent[b]=a;
    size[a]+=size[b];
} 
int main() {
    cout << "Vui long nhap so luong dinh:";cin >> n;
    make_set();
    return 0;
}