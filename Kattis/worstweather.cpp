#include <iostream>
#include <algorithm>

using namespace std;
#define MAXN 50000
int A[MAXN], Y[MAXN], T[4*MAXN];

void build(int idx, int l, int r){
    if(l==r){
        T[idx]=A[l];
        return;
    }
    int mid = (l+r)>>1;
    build(idx*2, l, mid);
    build(idx*2+1, mid+1, r);
    T[idx]=max(T[idx*2], T[idx*2+1]);
}

int query(int idx,int l,int r,int ql,int qr){
    if(ql>qr)return 0;
    if(l>=ql && r<=qr){
        return T[idx];
    }
    int mid = (l+r)>>1;

    auto p1 = query(idx*2, l, mid, ql, min(mid,qr));
    auto p2 = query(idx*2+1, mid+1, r, max(ql,mid+1), qr);
    return max(p1, p2);

}

int main(){
    int n,l,r,m,lid,rid,lval,rval;
    bool f=1,mb;
    while(scanf("%d", &n),n){
        for(int i=0;i<n;i++){
            scanf("%d %d", &Y[i], &A[i]);
        }
        scanf("%d", &m);
        if(!f)
        printf("\n");
        f=0;
        build(1,0,n-1);
        for(int i=0;i<m;i++){
            scanf("%d %d", &l,&r);
            lid = lower_bound(Y,Y+n, l)-Y;
            rid = lower_bound(Y,Y+n, r)-Y;
            lval=1e9+1;
            mb=0;
            if(rid-lid!=r-l)mb=1;
            if(lid!=n&&Y[lid]==l)lval = A[lid],lid++;
            else mb=1;
            if(rid!=n&&Y[rid]==r)rval = A[rid];
            else {mb=1;rval=lval;}
            rid--;

            auto it = query(1,0,n-1,lid,rid);
            if(rval<=lval && rval>it){
                if(mb)printf("maybe\n");
                else printf("true\n");
            }
            else printf("false\n");
        }
    }
}