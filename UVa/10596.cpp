#include <iostream>
#include <vector>
using namespace std;
int deg[200];
bool vis[200];
vector<int>adj[200];
void dfs(int u){
    vis[u]=true;
    for(int v:adj[u]){
        if(!vis[v])dfs(v);
    }
}
int main()
{
    int n,m;
    while (scanf("%d%d", &n,&m)!=EOF){
        for(int i=0;i<n;i++)deg[i]=0, adj[i].clear(), vis[i]=false;
        int u,v;
        for(int i=0;i<m;i++){

            scanf("%d%d", &u,&v);
            deg[u]++;
            deg[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool pos= true;
        if(m!=0)
            dfs(u);
        else
            pos=false;
        for(int i=0;i<n;i++)if(deg[i]&1||(!vis[i]&&deg[i]))pos= false;
        printf("%s\n", pos?"Possible":"Not Possible");
    }
}