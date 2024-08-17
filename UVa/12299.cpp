#include <iostream>
#include <climits>
using namespace std;
#define MAXN 100000
int A[MAXN], tree[4*MAXN];

void build(int idx, int l, int r){
    if(l==r){
        tree[idx] = A[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
    tree[idx] = min(tree[2*idx], tree[2*idx+1]);
}

void update(int idx, int l, int r, int ql, int val){
    if(l==r){
        tree[idx] = val;
        A[l] = val;
        return;
    }
    int mid = (l+r)/2;
    if(ql<=mid)update(2*idx, l, mid, ql, val);
    else update(2*idx+1, mid+1, r, ql, val);
    tree[idx] = min(tree[2*idx], tree[2*idx+1]);
}

int query(int idx, int l, int r, int ql, int qr){
    if(ql>qr)return INT_MAX;
    if(ql<=l && qr>=r)return tree[idx];
    int mid = (l+r)/2;
    return min(query(2*idx, l, mid, ql, min(mid, qr)), query(2*idx+1, mid+1, r,
                                                             max(ql, mid+1), qr));
}

int V[12];

int main(){
    int N,q,l,r,a;
    char c;
    scanf("%d %d", &N, &q);
    for(int i=0;i<N ; i++)scanf("%d", A+i);
    build(1, 0, N-1);
    while(q--){
        scanf(" %c", &c);
        if(c=='q'){
            scanf("uery(%d,%d)", &l, &r);
            printf("%d\n", query(1, 0, N-1, l-1, r-1));
        }
        else {
            while(c!='(')scanf("%c",&c);
            int m=0;
            while(c!=')')scanf("%d%c", V+m, &c), m++;
            a=A[V[0]-1];
            for(int i=0;i<m-1; i++)update(1, 0, N-1, V[i]-1, A[V[i+1]-1]);
            update(1, 0, N-1, V[m-1]-1, a);
        }
    }
    return 0;

}