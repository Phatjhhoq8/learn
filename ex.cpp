#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#define MAX_M 100
#define MAX_N 100
typedef struct {
	int m, n;
	int A[MAX_M][MAX_N];
	int r, c;
} State;
void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void init_state(State *S,char *fn){
    FILE *fi=fopen(fn,"r");
    fscanf(fi,"%d%d",&(S->m),&(S->n));
    for(int i=0;i<S->m;++i){
        for(int j=0;j<S->n;++j){
            fscanf(fi,"%d",&(S->A[i][j]));
        }
    }
    fscanf(fi,"%d%d",&(S->r),&(S->c));
    fclose(fi);
}
void print_state(State S){
    for(int i=0;i<S.m;i++){
        for(int j=0;j<S.n;j++){
            if(i==S.r && j==S.c) printf(".. ");
            else printf("%2d ",S.A[i][j]);
        }
        printf("\n");
    }
    //printf("%d %d\n",S.r,S.c);
}
int is_finished(State S){
    for(int i=0;i<S.m;++i){
        for(int j=0;j<S.n;++j){
            if(S.A[i][j]!=i*S.n+j+1) return 0;
        }
    }
    return 1;
}
int up(State S,State *N){
    *N=S;
    if(N->r){
        int tmp=N->A[N->r][N->c];
        N->A[N->r][N->c]=N->A[N->r-1][N->c];
        N->A[--(N->r)][N->c]=tmp;
        return 1;
    }
    return 0;
}
int down(State S,State *N){
    *N=S;
    if(N->m-N->r-1){
        int tmp=N->A[N->r][N->c];
        N->A[N->r][N->c]=N->A[N->r+1][N->c];
        N->A[++N->r][N->c]=tmp;
        return 1;
    }
    return 0;
}
int left(State S,State *N){
    *N=S;
    if(N->c){
        int tmp=N->A[N->r][N->c];
        N->A[N->r][N->c]=N->A[N->r][N->c-1];
        N->A[(N->r)][--N->c]=tmp;
        return 1;
    }
    return 0;
}
int right(State S,State *N){
    *N=S;
    if(N->n-N->c-1){
        int tmp=N->A[N->r][N->c];
        N->A[N->r][N->c]=N->A[N->r][N->c+1];
        N->A[(N->r)][++N->c]=tmp;
        return 1;
    }
    return 0;
}
char* finit(){
    char *fn=strdup("newgame.txt");
    FILE *fo=fopen(fn,"w");
    int n;scanf("%d",&n);
    fprintf(fo,"%d %d",n,n);
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a[i][j]=i*n+j+1;
        }
    }
    srand(time(NULL));
    for(int i=0,count=0;i<=n*n/2 || count&1;i++){
        int x1=rand()%n,y1=rand()%n;
        int x2=rand()%n,y2=rand()%n;
        if(x1==x2 && y1==y2) continue;
        if(x1==n-1 && y1==n-1 || x2==n-1 && y2==n-1) continue;
        swap(&a[x1][y1],&a[x2][y2]);
        count++;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fprintf(fo," %d",a[i][j]);
        }
    }
    fprintf(fo," %d %d",n-1,n-1);
    fclose(fo);
    return fn;
}
int main(){
    char *fn;//scanf("%s ",fn);
    fn=finit();
    State S;
    init_state(&S,fn);
    system("cls");
    print_state(S);
    char *wl="GET UP, FIGHT FOR YOUR FUTURE, TRY AGAIN TO GAIN!";
    char s[100];
    while(scanf("%s",s),strcmp(s,"E")!=0){
        system("cls");
        State N;
        if (strcmp(s,"W")==0) {if(up(S,&N)) S=N;else printf("Illegal move.\n");Sleep(1000);system("cls");}
        else if (strcmp(s,"S")==0) {if(down(S,&N)) S=N;else printf("Illegal move.\n");Sleep(1000);system("cls");}
        else if (strcmp(s,"A")==0) {if(left(S,&N)) S=N;else printf("Illegal move.\n");Sleep(1000);system("cls");}
        else if (strcmp(s,"D")==0) {if(right(S,&N)) S=N;else printf("Illegal move.\n");Sleep(1000);system("cls");}
        else {printf("Unknown command, please enter: W FOR UP, S FOR DOWN, A FOR LEFT, D FOR RIGHT or E FOR EXIT\n");Sleep(1000);system("cls");}
        if(is_finished(S)) {wl="YOU ARE IN THE TOP 1% INTELLIGENT PEOPLE IN THE WORLD!";break;}
        else print_state(S);
    }
    print_state(S);
    printf("%s",wl);
    return 0;
}

