#include <iostream>
#include <vector>
using namespace std;

vector<int>adjL[10000];
int dfsL[10000], dfsN[10000], par[10000], c;

int Find(int x){if(par[x]==-1) return x; return par[x]=Find(par[x]);}

void Union(int x, int y){par[Find(x)] = Find(y);}

void dfs(int u, int p){
    dfsL[u]=dfsN[u]=c++;
    for(int v:adjL[u]){
        if(dfsN[v]==-1){
            dfs(v, u);
            if(dfsL[v]<=dfsN[u])Union(u,v);
            dfsL[u] = min(dfsL[v], dfsL[u]);
        }
        else if(v!=p)
            dfsL[u] = min(dfsL[u], dfsN[v]); //cycle-already taken care of
    }
}

int main(){
    int N, M, u,v;
    scanf("%d%d",&N,&M);
    for(int i=0;i<N;i++)adjL[i].clear(),dfsN[i]=par[i]=-1;
    while(M--){
        scanf("%d%d", &u,&v);
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }
    c=0;
    int ret=0;
    dfs(0,-1);
    for(int i=0;i<N;i++)if(Find(i)==Find(0))ret++;
    printf("%d\n",ret);
}