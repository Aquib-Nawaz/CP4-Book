#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<int>adjL[1001];
int dfsL[1001], dfsN[1001], c,r;

pair<int,int>weak[10000];

void dfs(int u, int p){
    dfsL[u]=dfsN[u]=c++;
    for(int v:adjL[u]){
        if(dfsN[v]==-1){
            dfs(v, u);
            if(dfsL[v]>dfsN[u])weak[r++]={min(u,v), max(u,v)};
            dfsL[u] = min(dfsL[v], dfsL[u]);
        }
        else if(v!=p)
            dfsL[u] = min(dfsL[u], dfsN[v]); //cycle-already taken care of
    }
}

int main(){
    int N, M, u,v;
    while(scanf("%d%d", &N, &M), N){
        for(int i=0;i<N;i++)adjL[i].clear(),dfsN[i]=-1;
        while(M--){
            scanf("%d%d", &u,&v);
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }

        c=r=0;
        for(int i=0;i<N;i++)
            if(dfsN[i]==-1)
                dfs(i,-1);
        sort(weak, weak+r);
        printf("%d", r);
        for(int i=0;i<r;i++)
            printf(" %d %d", weak[i].first, weak[i].second);
        printf("\n");
    }
}