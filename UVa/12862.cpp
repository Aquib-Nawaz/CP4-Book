#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int,int>>adj[100001];
bool F[100001];

pair<int,int> dfs(int u){
    int tot=0,mx=0;
    pair<int,int>t;
    for(auto v:adj[u]){
        t = dfs(v.first);
        if(t.first<0)continue;
        tot+=t.first+v.second;
        mx = max(mx,t.second+v.second);
    }
    if(tot==0 && !F[u])return {-1,-1};
    return {tot,mx};
}

int main(){
    int n,f,u,v,w;
    while(scanf("%d%d",&n,&f)!=-1){
        for(int i=0;i<n-1;i++){
            scanf("%d%d%d",&u,&v,&w);
            adj[u].push_back({v,w});
        }
        for(int i=0;i<f;i++)
            scanf("%d",&u),F[u]= true;
        pair<int,int>ans = dfs(1);
        printf("%d\n",ans.first-ans.second);
        for(int i=1;i<=n;i++)adj[i].clear(),F[i]=false;
    }
}