#include <iostream>
using namespace std;

int A[1000001];
int ans=0;
void solve(int lo, int hi, int lb, int ub){
    if(lo>hi)return;
    int mid = (lo+hi)>>1;
    if(A[mid]<ub&&A[mid]>lb)ans++;
    solve(lo, mid-1, lb, min(A[mid],ub));
    solve(mid+1, hi, max(lb,A[mid]), ub);
}

int main(){
    int n,m,a,c,x;
    scanf("%d %d %d %d %d",&n,&m,&a,&c,&x);
    A[0]=x;
    for(int i=1;i<=n;i++){
        A[i]=(int)(((long long)A[i-1]*a+c)%m);
    }
    solve(1,n,-1,m);
    printf("%d",ans);
}