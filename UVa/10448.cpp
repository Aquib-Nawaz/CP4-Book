#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
using namespace std;

typedef long long ll;

ll dp[100001];
unordered_map<int, int>adj[51];
int height[51], par[51],arr[51], sz;

void dfs(int u, int p){
    par[u]=p;
    height[u]=height[p]+1;
    for(pair<int,int> v:adj[u]){
        if(v.first!=p){
            dfs(v.first,u);
        }
    }
}

int main(){

    int T, n, m,u,v,w,q,_u,_v;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)adj[i].clear();
        for(int _=0;_<m;_++){
            scanf("%d%d%d",&u,&v,&w);
            adj[u].emplace(v,w);
            adj[v].emplace(u,w);
        }
        scanf("%d",&q);
        height[0]=0;
        memset(par,-1,sizeof(par));
        for(int i=1;i<=n;i++){
            if(par[i]==-1)dfs(i,0);
        }
        while (q--){
            scanf("%d%d%d",&u,&v,&w);
            _u=u,_v=v;
            while(height[_u]>height[_v])
                _u=par[_u];
            while(height[_v]>height[_u])
                _v=par[_v];
            while(_u!=_v){
                _u=par[_u];
                _v=par[_v];
            }
            if(_u==0){
                printf("No\n");
                continue;
            }
            sz=0;
            _v = u;

            while(_v!=_u){
                w-=adj[_v][par[_v]];
                arr[sz++]=2*adj[_v][par[_v]];
                _v = par[_v];
            }
            _v=par[v];
            if(v!=_u ){
                while(_v!=_u){
                    w-=adj[_v][par[_v]];
                    arr[sz++]=2*adj[_v][par[_v]];
                    _v = par[_v];
                }
                w-=adj[v][par[v]];
            }
            else sz--;
            if(w<0){
                printf("No\n");
                continue;
            }
            memset(dp,-1,(w+1)*sizeof(dp[0]));
            dp[0]=0;
            for(int i=0;i<sz;i++){
                for(int j=arr[i];j<=w;j++){
                    if(dp[j-arr[i]]==-1)continue;
                    if(dp[j]!=-1)dp[j]=min(dp[j],dp[j-arr[i]]+1);
                    else dp[j] = 1+dp[j-arr[i]];
                }
            }
            if(dp[w]!=-1)printf("Yes %lld\n",2*dp[w]+sz+1);
            else printf("No\n");
        }
        if(T!=0)printf("\n");
    }
}