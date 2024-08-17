#include <iostream>
#include <cstring>
using namespace std;

int edge[10], dp[10][1<<9],n;

int solve(int pos, int mask){
    if(mask==0)return edge[pos]&1;

    int &ret=dp[pos][mask];
    if(ret!=-1)return ret;
    ret=0;
    for(int i=1;i<n;i++){
        if(mask&1<<(i-1) && edge[pos]&1<<i){
            ret+=solve(i,mask^1<<(i-1));
        }
    }
    return ret;
}

int main(){

    int T,m,u,v,C=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)edge[i]=(1<<n)-1;
        for(int i=0;i<m;i++){
            scanf("%d %d",&u,&v);
            u--,v--;
            edge[u]^=(1<<v);
            edge[v]^=(1<<u);
        }
        memset(dp,-1,sizeof dp);
        printf("Case #%d: %d\n", ++C, solve(0,(1<<(n-1))-1)/2%9901);
    }
}