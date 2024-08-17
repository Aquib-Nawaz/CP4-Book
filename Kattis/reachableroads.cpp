#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef vector<int>vi;
vi adjL[1000];
bool vis[1000];
void dfs(int u){
    vis[u]=true;
    for(auto v:adjL[u]){
        if(!vis[v])dfs(v);
    }
}
int main(){
    int T,n,m,u,v;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)adjL[i].clear(),vis[i]=false;
        for(int i=0;i<m;i++)scanf("%d%d",&u,&v), adjL[u].push_back(v), adjL[v].push_back(u);
        int cnt=0;
        for(int i=0;i<n;i++)if(!vis[i])dfs(i),cnt++;
        printf("%d\n",cnt-1);
    }
}