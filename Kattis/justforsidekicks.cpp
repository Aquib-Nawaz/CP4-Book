#include <iostream>
#include <cstring>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define MAXN 200000

int A[MAXN], tree[6][MAXN+1];
long long V[6];
void update(int i, int v, int arr[], int n){for(;i<=n;i+=i&-i)arr[i]+=v;}
int query(int i, int arr[]){int sum=0;for(;i;i-=i&-i)sum+=arr[i]; return sum;}
void build(int n){
    REP(i,6)REP(j,n){
        if(A[j]==i){
            tree[i][j+1]++;
        }
        if(j+1+((j+1)&(-j-1))<=n)
            tree[i][j+1+((j+1)&(-j-1))]+=tree[i][j+1];
    }
}
long long rsq(int l, int r){
    long long ret=0;
    REP(i,6)
        ret+=(query(r, tree[i])-query(l-1, tree[i]))*V[i];
    return ret;
}
int main(){
    int N,Q, l ,r, type;
    char c;
    scanf("%d %d", &N, &Q);
    REP(i,6)scanf("%lld ", V+i);
    REP(i,N){scanf("%c", &c);A[i]=c-'1';}
    memset(tree, 0, sizeof tree);
    build(N);
    bool f=0;
    REP(i,Q){
        scanf("%d %d %d", &type, &l, &r);
        if(type==1){
            update(l,-1, tree[A[l-1]], N);
            update(l,1, tree[r-1], N);
            A[l-1]=r-1;
        }else if(type==2){
            V[l-1]=r;
        }
        else {
            if(f)
                printf("\n");
            f=1;
            printf("%lld", rsq(l,r));
        }
    }
}