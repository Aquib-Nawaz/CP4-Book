#include <iostream>
#include <vector>
using namespace std;

vector<int>adjL[2][20001];
int x, order[20000],c,curCC, cc[20000];
bool vis[20001], indeg[20000], outdeg[20000];

void dfs(int u){
    vis[u]=true;
    if(x==1)
        cc[u]=curCC;
    for(auto v:adjL[x][u]){
        if(!vis[v])dfs(v);
        else if(x==1 && cc[v]!=curCC) outdeg[cc[v]]=indeg[curCC]=true;
    }
    if(x==0)order[--c]=u;
}

int main(){
    int T,N,M,u,v;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &N, &M);
        for(int i=0;i<N;i++){
            vis[i]=indeg[i]=outdeg[i]=false; adjL[0][i].clear(); adjL[1][i].clear();
        }
        for(int i=0;i<M;i++){
            scanf("%d %d",&u,&v);
            u--,v--;
            adjL[0][u].push_back(v);
            adjL[1][v].push_back(u);

        }
        x=0, c=N;
        for(int i=0;i<N;i++)if(!vis[i]) dfs(i);
        for(int i=0;i<N;i++)vis[i]  = false;
        x=1,curCC=0;
        for(int i=0;i<N;i++)if(!vis[order[i]]) dfs(order[i]), curCC++;
        int ans=0;
        if(curCC!=1) {
            u=v=0;
            for(int i=0;i<curCC;i++)if(!indeg[i])u++;
            for(int i=0;i<curCC;i++)if(!outdeg[i])v++;
            ans = max(u,v);
        }
        printf("%d\n", ans);
    }
}
