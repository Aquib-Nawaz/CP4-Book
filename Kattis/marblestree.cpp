#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef long long ll;

vector<int>adj[10001];
int M[10001];
bool Par[10001];
ll ans=0;

int dfs(int u, int p){
    int needed = 0;
    for(int v:adj[u]){
        needed+=dfs(v,u);
    }
    needed+=1-M[u];
    ans+=abs(needed);
    if(needed<0)M[p]-=needed,needed=0;
    return needed;
}

int main(){
    int n,u,v,d;
    while(scanf("%d",&n),n){
        memset(Par,0,sizeof Par);
        for(int i=0;i<n;i++){
            scanf("%d%d%d",&u,&v,&d);
            M[u]=v;
            adj[u].clear();
            for(int j=0;j<d;j++)scanf("%d",&v),adj[u].push_back(v),
                        Par[v]=true;
        }
        for(u=1;u<=n;u++)if(!Par[u])break;
        dfs(u,0);
        printf("%lld\n",ans);
        ans=0;
    }
}