#include <iostream>
#include <vector>
using namespace std;

vector<int>adjL[100];
int dfsL[100], dfsN[100], c;


bool dfs(int u, int p){
    dfsL[u]=dfsN[u]=c++;
    bool ret=false;
    for(int v:adjL[u]){
        if(dfsN[v]==-1){
            ret|=dfs(v, u);
            if(dfsL[v]>dfsN[u])ret=true;
            dfsL[u] = min(dfsL[v], dfsL[u]);
        }
        else if(v!=p)
            dfsL[u] = min(dfsL[u], dfsN[v]); //cycle-already taken care of
    }
    return ret;
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
        c=0;
        bool ret=false;
        for(int i=0;i<N;i++)if(dfsN[i]==-1)ret|=dfs(i,-1);
        printf("%s\n", ret?"Yes":"No");
    }
}