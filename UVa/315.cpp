#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int>adjL[100];
int dfsL[100], dfsN[100],c;

int dfs(int u, int p){
    dfsL[u]=dfsN[u]=c++;
    int ret=0;
    bool art=false;
    int nch=0;
    for(int v:adjL[u]){
        if(dfsN[v]==-1){
            nch++;
            ret+=dfs(v, u);
            if(dfsL[v]>=dfsN[u])art=true;
            dfsL[u] = min(dfsL[v], dfsL[u]);
        }
        else if(v!=p)
            dfsL[u] = min(dfsL[u], dfsN[v]); //cycle
    }
    if(u==0)art=nch>1;
    return ret+art;
}

int main(){
    int N, u,v;
    char c;
    while(scanf("%d", &N), N){
        while(scanf("%d", &u),u){
            u--;
            while(true){
                scanf(" %d%c", &v,&c);
                v--;
                adjL[u].push_back(v);
                adjL[v].push_back(u);
                if(c=='\n')break;
            }
        }
        memset(dfsN, -1, sizeof dfsN);
        c=0;
        printf("%d\n", dfs(0, -1));
        for(int i=0;i<N;i++)adjL[i].clear();
    }
}