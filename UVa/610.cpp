#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int>adjL[1001];
int dfsN[1001], dfsL[1001],c;
bool inStack[1001];

void dfs(int u, int p){
    dfsN[u]=dfsL[u]=++c;
    inStack[u]= true;
    for(int v:adjL[u]) {
        if (dfsN[v] == -1) {
            dfs(v,u);
            if (dfsL[v] > dfsN[u]) {
                printf("%d %d\n", v, u);
            }
            printf("%d %d\n", u, v);
            dfsL[u] = min(dfsL[u], dfsL[v]);
        }
        else if(v!=p){
            dfsL[u] = min(dfsL[u], dfsL[v]);
            if(inStack[v])printf("%d %d\n",u,v);
        }
    }
    inStack[u]= false;
}

int main(){
    int N,M,u,v,C=0;
    while (scanf("%d%d", &N,&M), N){
        for(int i=1;i<=N;i++)adjL[i].clear();
        for(int i=0;i<M;i++)scanf("%d%d",&u,&v),adjL[u].push_back(v),adjL[v].push_back(u);
        memset(dfsN,-1,sizeof dfsN);
        memset(inStack,0,sizeof inStack);
        c=0;
        printf("%d\n\n", ++C);
        dfs(1,0);
        printf("#\n");
    }

}
