#include <iostream>
#include <algorithm>
using namespace std;

int par[20000];
int find(int x){
    if(par[x]==-1)return x;
    return par[x]=find(par[x]);
}

bool merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return false;
    par[x]=y;
    return true;
}

struct Edge{
    int u,v,w;
}edge[30000], edge1[20000];

int main(){
    int N,M;
    while(scanf("%d%d", &N,&M),N) {
        for (int i = 0; i < N; i++)par[i] = -1;
        for (int i = 0; i < M; i++) {
            scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
        }
        sort(edge, edge + M, [](Edge &a, Edge &b) { return a.w < b.w; });
        int j = 0, cost = 0;
        for (int i = 0; i < M; i++) {
            if (merge(edge[i].u, edge[i].v)) {
                cost += edge[i].w;
                edge1[j++] = {min(edge[i].u, edge[i].v), max(edge[i].u, edge[i].v), edge[i].w};
            }
        }
        if (j != N - 1)printf("Impossible\n");
        else {
            printf("%d\n", cost);
            sort(edge1, edge1 + j, [](Edge &a, Edge &b) { return a.u!=b.u?a.u < b.u:a.v < b.v; });
            for (int i = 0; i < j; i++) {
                printf("%d %d\n", edge1[i].u, edge1[i].v);
            }
        }
    }
}