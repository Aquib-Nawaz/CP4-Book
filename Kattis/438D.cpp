#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 100001
typedef long long ll;

using namespace std;


int A[MAX];

ll tree[4*MAX];
int maxv[4*MAX];

void build(int idx, int l, int r){
    if(l==r){
        tree[idx]=maxv[idx]=A[l];
        return;
    }
    int mid=(l+r)/2;
    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
    tree[idx] = tree[2*idx] + tree[2*idx+1];
    maxv[idx] = max(maxv[2*idx], maxv[2*idx+1]);
}

void find_and_update(int idx, int sr, int er, int l, int r, int x){
    if(l>r||maxv[idx]<x)
        return;
    if(sr==er){
        tree[idx]=maxv[idx]=tree[idx]%x;
        return;
    }
    int mid=(sr+er)/2;
    find_and_update(2*idx, sr, mid, l, min(r, mid), x);
    find_and_update(2*idx+1, mid+1, er, max(mid+1, l), r, x);
    tree[idx]=tree[2*idx]+tree[2*idx+1];
    maxv[idx]=max(maxv[2*idx], maxv[2*idx+1]);
}

void update(int idx, int sr, int er, int l, int r, int x){
    if(l>r)
        return;
    if(sr==l && er==r){
        tree[idx]=(sr-er+1)*x;
        maxv[idx]=x;
        return;
    }
    else{
        int mid=(sr+er)/2;
        update(2*idx, sr, mid, l, min(r, mid), x);
        update(2*idx+1, mid+1, er, max(mid+1, l), r, x);
        tree[idx]=tree[2*idx]+tree[2*idx+1];
        maxv[idx]=max(maxv[2*idx], maxv[2*idx+1]);
    }
}

ll query(int idx, int sr, int er, int l, int r){
    if(l>r)
        return 0;
    if(l==sr && r==er)
        return tree[idx];
    int mid=(sr+er)/2;

    ll ret=query(2*idx, sr, mid, l, min(r, mid));
    ret+=query(2*idx+1, mid+1, er, max(mid+1, l), r);
    return ret;
}


int main(){
    int n,q;
    scanf("%d %d", &n, &q);
    for(int i=0; i<n; i++)
        scanf("%d", &A[i]);
    build(1, 0, n-1);
    while(q--){
        int t,l,r,x;
        scanf("%d", &t);
        switch(t){
            case 1:
                scanf("%d %d", &l, &r);
                printf("%lld\n", query(1, 0, n-1, l-1, r-1));
                break;
            case 2:
                scanf("%d %d %d", &l, &r, &x);
                find_and_update(1, 0, n-1, l-1, r-1, x);
                break;
            case 3:
                scanf("%d %d", &l, &x);
                update(1, 0, n-1, l-1, l-1, x);
                break;
        }
    }
    return 0;

}