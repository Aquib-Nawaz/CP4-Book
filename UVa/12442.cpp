#include <iostream>
using namespace std;
int C[50001], dp[50001];
bool inStack[50001];
int dfs(int u){
    if(dp[u]!=-1)return dp[u];
    int v=C[u],ans=0;
    inStack[u]=true;
    int ret;
    if(inStack[v]){
        ans++;
        for(;v!=u;v=C[v])ans++;
        v=C[u], dp[u]=ans;
        for(;v!=u;v=C[v])dp[v]=ans;
        ret = ans;
    }
    else{
        ret = dfs(v);
        if(dp[u]==-1)
            ret++;
    }
    inStack[u]=false;
    return dp[u]=ret;
}

int main() {
    int T,N,Cs=0,u,v;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &N);
        for(int i=1;i<=N;i++)scanf("%d%d",&u,&v), inStack[i]=false,dp[i]=-1, C[u]=v;
        int mx=0,mxid;
        for(int i=1;i<=N;i++)if(dp[i]==-1){
            int ret = dfs(i);
            if(ret>mx){
                mx = ret;
                mxid = i;
            }
        }
        printf("Case %d: %d\n",++Cs, mxid);
    }
}