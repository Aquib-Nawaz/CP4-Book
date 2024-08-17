#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
#define MAXN 100000
int A[MAXN+1],M[4*MAXN];

void build(int idx, int l, int r){
    if(l==r){
        M[idx]=1;
        return;
    }
    int mid = (l+r)>>1;
    build(idx*2, l, mid);
    build(idx*2+1, mid+1, r);
    M[idx] = max(M[2*idx],M[2*idx+1]);
    if(A[mid]==A[mid+1]){
        int t= upper_bound(A+l,A+r+1,A[mid])-lower_bound(A+l,A+r,A[mid]);
        M[idx]=max(M[idx],t);
    }
}

int query(int idx,int l,int r,int ql,int qr){
    if(ql>qr)return -100001;
    if(l>=ql && r<=qr){
        return M[idx];
    }
    int mid = (l+r)>>1;

    auto p1 = query(idx*2, l, mid, ql, min(mid,qr));
    auto p2 = query(idx*2+1, mid+1, r, max(ql,mid+1), qr);
    int ret = max(p1,p2);
    if(ql<=mid&&qr>mid&&A[mid]==A[mid+1])
        ret=(int)max((long)ret,upper_bound(A+ql,A+qr+1,A[mid])-lower_bound(A+ql,A+qr, A[mid]));
    return ret;

}

int main(){
    int n,l,r,m,d;
    char c;
    A[0]=-100001;
    while(scanf("%d %d", &n,&m),n){
        for(int i=1;i<=n;i++)scanf("%d",&A[i]);
        build(1,1,n);
        while(m--){
            scanf("%d %d",&l,&r);
            printf("%d\n",query(1,1,n,l,r));
        }
    }
    return 0;
}