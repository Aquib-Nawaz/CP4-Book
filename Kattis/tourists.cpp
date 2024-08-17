#include <iostream>
#include <vector>
using namespace std;

int height[200001], par[200001][18];
vector<int>adj[200001];

void dfs(int v, int p){
    par[v][0] = p;
    height[v]=p==-1?0:height[p]+1;
    for(int i = 1; i < 18 && par[v][i-1] != -1; i++){
        par[v][i] = par[par[v][i-1]][i-1];
    }
    for(int u : adj[v]){
        if(u != p){
            dfs(u, v);
        }
    }
}

int lca(int u, int v){
    if(height[u] < height[v]){
        swap(u, v);
    }
    int diff = height[u] - height[v];
    for(int i = 17; i >= 0; i--){
        if(diff & (1 << i)){
            u = par[u][i];
        }
    }
    if(u == v){
        return u;
    }
    for(int i = 17; i >= 0; i--){
        if(par[u][i] != -1 && par[u][i] != par[v][i]){
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}

int main(){
    int n,u,v;
    scanf("%d", &n);
    for(int i=0;i<n-1;i++){
        scanf("%d%d", &u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,-1);
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=2*i;j<=n;j+=i){
            int l = lca(i,j);
            ans+=height[i]+height[j]-2*height[l]+1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}