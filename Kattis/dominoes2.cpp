#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef vector<int>vi;
vi adjL[10001];
bool vis[10001];
int cnt;
void dfs(int u){
    vis[u]=true;
    cnt++;
    for(auto v:adjL[u]){
        if(!vis[v])dfs(v);
    }
}
int main(){
    int T,n,m,u,v,l;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&n,&m,&l);
        for(int i=1;i<=n;i++)adjL[i].clear(),vis[i]=false;
        for(int i=0;i<m;i++)scanf("%d%d",&u,&v), adjL[u].push_back(v);
        cnt=0;
        for(int i=0;i<l;i++){
            scanf("%d",&u);
            if(!vis[u])dfs(u);
        }
        printf("%d\n",cnt);
    }
}