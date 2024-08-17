#include <iostream>
#include <algorithm>

using namespace std;
#define MAXN 100000
int A[MAXN+1], T[4*MAXN];
#define sign(x) ((x > 0) - (x < 0))

void build(int idx, int l, int r){
    if(l==r){
        T[idx]=A[l];
        return;
    }
    int mid = (l+r)>>1;
    build(idx*2, l, mid);
    build(idx*2+1, mid+1, r);
    T[idx]=T[idx*2]*T[idx*2+1];
}

int query(int idx,int l,int r,int ql,int qr){
    if(ql>qr)return 1;
    if(l>=ql && r<=qr){
        return T[idx];
    }
    int mid = (l+r)>>1;

    auto p1 = query(idx*2, l, mid, ql, min(mid,qr));
    auto p2 = query(idx*2+1, mid+1, r, max(ql,mid+1), qr);
    return p1*p2;

}

void update(int idx,int l,int r,int ql,int v){

    if(l==r){
        T[idx]=v;
        return;
    }
    int mid = (l+r)>>1;
    if(ql<=mid)
     update(idx*2, l, mid, ql, v);
    else update(idx*2+1, mid+1, r, ql, v);
    T[idx]=T[idx*2]*T[idx*2+1];
}

char to_char(int x){
    if(x>0)return '+';
    else if(x<0)return '-';
    else return '0';
}

int main(){
    int n,l,r,m,d;
    char c;
    while(scanf("%d %d", &n,&m)!=-1){
        for(int i=1;i<=n;i++)scanf("%d",&d),A[i]=sign(d);
        build(1,1,n);
        while(m--){
            scanf(" %c %d %d",&c, &l,&r);
            if(c=='P')
                printf("%c", to_char(query(1,1,n,l,r)));
            else
                update(1,1,n,l,sign(r));
        }
        printf("\n");
    }
}