#include <iostream>
#include <vector>
using namespace std;

vector<int>adjL[200];
char vis[200];

bool dfs(int u){
    for(auto v: adjL[u]){
        if(vis[v]==0){
            vis[v]=3-vis[u];
            if(!dfs(v)) return false;
        }
        else if(vis[v]==vis[u])
            return false;
    }
    return true;
}

int main(){
    int N, M, a, b;
    while(scanf("%d%d", &N, &M), N){
        for(int i=0;i<N;i++)adjL[i].clear(), vis[i]=0;
        for(int i=0;i<M;i++)scanf("%d%d", &a, &b), adjL[a].push_back(b), adjL[b].push_back(a);
        vis[0]=1;
        if(dfs(0))printf("BICOLORABLE.\n");
        else printf("NOT BICOLORABLE.\n");
    }
}