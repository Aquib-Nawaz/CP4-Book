#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<int>adjL[100];
pair<int,int>dp[100];
int V[100];

pair<int,int> dfs(int u){
    if(adjL[u].empty())return {0,u};
    if(dp[u].first!=-1)return dp[u];
    int mxid=adjL[u][0];
    for(int v:adjL[u]){
        if(V[v]>V[mxid])mxid=v;
    }
    pair<int,int> ret=dfs(mxid);
    ret.first+=V[mxid];
    return dp[u]=ret;
}


int main(){
    int T,N,M,C=0;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N,&M);
        for(int i=0;i<N;i++)scanf("%d", V+i), dp[i]={-1,-1}, adjL[i].clear();
        for(int i=0;i<M;i++){
            int u,v;
            scanf("%d %d", &u,&v);
            adjL[u].push_back(v);
        }
        pair<int,int>ans=dfs(0);
        printf("Case %d: %d %d\n", ++C, ans.first, ans.second);
    }
}