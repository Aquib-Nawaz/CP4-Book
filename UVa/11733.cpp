#include <iostream>
#include <algorithm>
using namespace std;

int par[10000];
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
}edge[100000];

int main(){
    int N,M,T,A,cost,C=0;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &N, &M,&A);
        for(int i=0;i<M;i++)scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w), edge[i].u--, edge[i].v--;
        cost = 0;
        for(int i=0;i<N;i++)par[i]=-1;
        sort(edge, edge + M, [](Edge &a, Edge &b) { return a.w < b.w; });
        int t=N;
        for (int i = 0; i < M && edge[i].w < A; i++) {
            if (merge(edge[i].u, edge[i].v)) {
                cost += edge[i].w, t--;
            }
        }
        printf("Case #%d: %d %d\n",++C, cost+t*A, t);
    }
}