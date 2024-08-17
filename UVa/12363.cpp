#include <iostream>
#include <vector>
using namespace std;

vector<int>adjL[10001];
int dfsL[10001], dfsN[10001], par[10001], c;

int Find(int x){
    if(par[x]==-1) return x;
    return par[x]=Find(par[x]);
}

void Union(int u, int v){u=Find(u), v=Find(v); par[u]=v;}

void dfs(int u, int p){
    dfsL[u]=dfsN[u]=c++;
    for(int v:adjL[u]){
        if(dfsN[v]==-1){
            dfs(v, u);
            if(dfsL[v]>dfsN[u])Union(u,v);
            dfsL[u] = min(dfsL[v], dfsL[u]);
        }
        else if(v!=p)
            dfsL[u] = min(dfsL[u], dfsN[v]); //cycle
    }
}

int main(){
    int N, M, u,v, Q;
    while(scanf("%d%d%d", &N, &M, &Q), N){
        for(int i=1;i<=N;i++)adjL[i].clear(),dfsN[i]=par[i]=-1;
        while(M--){
            scanf("%d%d", &u,&v);
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }

        c=0;
        for(int i=1;i<=N;i++)
            if(dfsN[i]==-1)
                dfs(i,-1);
        for(int i=0;i<Q;i++)scanf("%d%d",&u,&v), printf("%c\n",Find(u)==Find(v)?'Y':'N');
        printf("-\n");
    }
}