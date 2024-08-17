#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

#define V 5000
bitset<V> dp[2][V];
vector<int>adj[2][V];
bool vis[2][V];
void dfs(int u, int x){
    if(vis[x][u]) return;
    vis[x][u]= true;
    bitset<V> &ret=dp[x][u];
    ret.set(u);
    for(int v:adj[x][u]){
        dfs(v,x);
        ret|=dp[x][v];
    }
}

int main(){
    int a,b,N,M,u,v;
    scanf("%d%d%d%d", &a,&b,&N,&M);
    for(int i=0;i<M;i++){
        scanf("%d%d", &u,&v);
        adj[0][u].push_back(v);
        adj[1][v].push_back(u);
    }
    for(int i=0;i<N;i++)for(int j=0;j<2;j++)vis[j][i]=false, dp[j][i].reset();
    for(int i=0;i<N;i++)dfs(i,0), dfs(i,1);
    int a1=0,a2=0,a3=0;
    for(int i=0;i<N;i++){
        if(dp[1][i].count()>b)a3++;
        if(N-dp[0][i].count()<a)a1++;
        if(N-dp[0][i].count()<b)a2++;
    }
    printf("%d\n%d\n%d\n", a1, a2, a3);
}