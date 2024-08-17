#include <iostream>
#include <cstring>
using namespace std;
int A[1<<14], W[1<<14];
#define REP(i,j,n) for(int i=j;i<(n);i++)
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        memset(W, 0, sizeof (int)*(1<<n));
        REP(i,0,1<<n)
            scanf("%d",&A[i]);
        REP(i,0,1<<n)REP(j,0,n)W[i]+=A[i^(1<<j)];
        int ans=0;
        REP(i,0,1<<n)REP(j,0,n)ans=max(ans, W[i]+W[i^(1<<j)]);
        printf("%d\n",ans);
    }
}