#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<int>adjL[100001];
int dfsL[100001], dfsN[100001], c, r;

pair<int,int>weak[100000];

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
    int N, d, u,v;
    while(scanf("%d", &N)!=-1){
        for(int i=0;i<N;i++)adjL[i].clear(),dfsN[i]=-1;
        for(int i=0;i<N;i++){
            scanf("%d (%d)",&u,&d);
            for(int j=0;j<d;j++)scanf("%d",&v), adjL[u].push_back(v);
        }

        c=r=0;
        for(int i=0;i<N;i++)
            if(dfsN[i]==-1)
                dfs(i,-1);
        sort(weak, weak+r);
        printf("%d critical links\n", r);
        for(int i=0;i<r;i++)
            printf("%d - %d\n", weak[i].first, weak[i].second);
        printf("\n");
    }
}