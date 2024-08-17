#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define REP(i,n) for (int i=0;i<n;i++)

#define MAXN 1024000
int A[MAXN], tree[4*MAXN];
char lazy[4*MAXN];

void build(int idx, int l, int r){
    if(l==r){
        tree[idx]=A[l];
        return;
    }
    int mid = (l+r)/2;
    build(idx*2, l, mid);
    build(idx*2+1, mid+1, r);
    tree[idx]=tree[idx*2]+tree[idx*2+1];
}

char combine(char a, char b){
    if(b=='F'||b=='E') return b;
    if(a=='F')return 'E';
    if(a=='E')return 'F';
    if(a=='I')return 0;
    return 'I';
}

void evaluate(int idx, int l, int r){
    switch(lazy[idx]){
        case 'F':
            tree[idx]=r-l+1;
            break;
        case 'E':
            tree[idx]=0;
            break;
        case 'I':
            tree[idx]=r-l+1-tree[idx];
            break;
    }
}
void push(int idx, int l, int r){
    if(lazy[idx]==0)return;
    evaluate(idx,l,r);
    if(l!=r ){
        lazy[idx*2]= combine(lazy[idx*2], lazy[idx]);
        lazy[idx*2+1]=combine(lazy[idx*2+1], lazy[idx]);
    }
    lazy[idx]=0;
}

void update(int idx, int l, int r, int ql, int qr, char v){
    push(idx, l, r);
    if(l>qr || r<ql)return;
    if(l>=ql && r<=qr){
        lazy[idx]= combine(lazy[idx], v);
        push(idx, l, r);
        return;
    }
    push(idx,l,r);
    int mid = (l+r)/2;
    update(idx*2, l, mid, ql, min(qr, mid), v);
    update(idx*2+1, mid+1, r, max(ql, mid+1), qr, v);
    tree[idx]=tree[idx*2]+tree[idx*2+1];
}

int query(int idx, int l, int r, int ql, int qr){
    if(l>qr || r<ql)return 0;
    push(idx,l,r);
    if(l>=ql && r<=qr)return tree[idx];
    int mid = (l+r)/2;
    return query(idx*2, l, mid, ql, min(qr, mid))+query(idx*2+1, mid+1, r, max(ql, mid+1), qr);
}

char line[51];
int main(){
    int T, m, d, l, q, r,C=0;
    char c;
    scanf("%d", &T);
    while(C++<T){
        printf("Case %d:\n", C);
        scanf("%d", &m);
        int id=0;
        REP(i,m){
            scanf("%d %s", &d, line);
            l = strlen(line);
            while(d--){
                REP(j,l)A[id++]=line[j]-'0';
            }
        }
        memset(lazy, 0, sizeof(lazy));
        build(1, 0, id-1);
        scanf("%d", &q);
        int j=0;
        REP(i,q){
            scanf(" %c %d %d", &c, &l, &r);
            if(c=='S'){
                printf("Q%d: %d\n", ++j, query(1, 0, id-1, l, r));
            }
            else
                update(1,0,id-1,l,r,c);
        }
    }
}