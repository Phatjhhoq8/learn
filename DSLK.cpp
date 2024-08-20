#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *pnext;
};
typedef struct node NODE;
struct listNode {
    NODE* pHead;
    NODE* pTail;
};
typedef struct listNode LIST;
void khoitao(LIST &l) {
    l.pHead=NULL;
    l.pTail=NULL;
}
NODE *khoitaoNode(int x) {
    NODE* p = new NODE;
    p-> data=x;
    p->pnext=NULL;
    return p;
}
void insertFirst(LIST &l,NODE *p) {
    if(l.pHead==NULL) {
        l.pHead=l.pTail=p;
    } else {
        p->pnext=l.pHead;
        l.pHead=p;
    }
}
void insertLast(LIST &l,NODE *p) {
    if(l.pHead==NULL) {
        l.pHead=l.pTail=p;
    } else {
        l.pTail->pnext=p;
        l.pTail=p;
    }
}
void giaiphong(LIST &l) {
    NODE *k =NULL;
    while(l.pHead!=NULL) {
        k=l.pHead;
        l.pHead=l.pHead->pnext;
        delete k;
    }
}
int main() {
    LIST l;
    khoitao(l);
    int n;cin >> n;
    for(int i = 1; i <= n; i++) {
        int x;cin >> x;
        NODE *p = khoitaoNode(x);
        insertLast(l,p);
    }
    for(NODE *k =l.pHead; k != NULL;k=k->pnext) {
        cout << k->data <<" ";
    }
    giaiphong(l);
    return 0;
}