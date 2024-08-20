#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *pLeft;
    struct node *pRight;
};
typedef struct node NODE;
typedef NODE* TREE;
void khoitao(TREE &t) {
    t=NULL;
}
void themNode(TREE &t,int x) {
    if(t==NULL) {
        NODE *p =new NODE;
        p->data=x;
        p->pLeft=NULL;
        p->pRight=NULL;
        t=p;
    } else if(t->data > x) {
        themNode(t->pLeft,x);
    } else if(t->data < x) {
        themNode(t->pRight,x);
    }
}
void NLR(TREE t) {
    if(t!= NULL) {
        cout << t->data << " ";
        NLR(t->pLeft);
        NLR(t->pRight);
    }
}
int main() {
    TREE t;
    khoitao(t);
    for(int i = 1; i <= 6;i++) {
        int x;cin >> x;
        themNode(t,x);
    }
    NLR(t);
    return 0;
}