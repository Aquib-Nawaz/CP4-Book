#include <algorithm>
#include <iostream>
#include <vector>

#define MAX 100001
using namespace std;


int A[MAX];
struct SEG{
    int gcd;
    int count=0;
};

int gcd(int a, int b){
    if(a==-1)
        return b;
    if(b==-1)
        return a;
    if(b==0)
        return a;
    return gcd(b, a%b);
}

struct SEG tree[4*MAX];

void build(int idx, int l, int r){
    if(l==r){
        tree[idx].gcd=A[l];
        tree[idx].count=1;
        return;
    }
    int mid=(l+r)/2;
    build(2*idx, l, mid);
    build(2*idx+1, mid+1, r);
    tree[idx].gcd = gcd(tree[2*idx].gcd, tree[2*idx+1].gcd);

    if(tree[idx].gcd==tree[2*idx].gcd)
        tree[idx].count+=tree[2*idx].count;
    if(tree[idx].gcd==tree[2*idx+1].gcd)
        tree[idx].count+=tree[2*idx+1].count;
}

struct SEG query(int idx, int sr, int er, int l, int r){
    if(l>r)
        return {-1, 0};
    if(l==sr && r==er)
        return tree[idx];

    int mid=(sr+er)/2;
    struct SEG p1=query(2*idx, sr, mid, l, min(r, mid));
    struct SEG p2=query(2*idx+1, mid+1, er, max(mid+1, l), r);
    struct SEG ret;
    int mgcd = gcd(p1.gcd, p2.gcd);
    if(p1.gcd==mgcd)
        ret.count+=p1.count;
    if(p2.gcd==mgcd)
        ret.count+=p2.count;
    ret.gcd=mgcd;
    return ret;
}


int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++)
        scanf("%d", &A[i]);
    build(1, 0, n-1);
    int q;
    scanf("%d", &q);
    while(q--){
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", r-l+1-query(1, 0, n-1, l-1, r-1).count);
    }
    return 0;

}