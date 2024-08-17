#include <iostream>
#include <algorithm>
using namespace std;

int par[501], V[501];
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
}edge[125000];

int diff(int x, int y){
    if(x>y)swap(x,y);
    int ret = y-x;
    return ret<=5?ret:10-ret;
}

int weight(int u, int v){
    int ans=0;
    while(u!=v){
        ans+=diff(u%10,v%10);
        u/=10;
        v/=10;
    }
    return ans;
}

int main(){
    int N,M,T,cost;
    scanf("%d", &T);
    while(T--) {
        scanf("%d", &N), M=0;
        cost=21;
        for (int i = 0; i < N; i++) {
            scanf("%d", V+i);
            par[i]=-1;
            cost = min(cost, weight(0,V[i]));
            for(int j=0;j<i;j++)
                edge[M++] = {i,j, weight(V[i],V[j])};
        }
        sort(edge, edge + M, [](Edge &a, Edge &b) { return a.w < b.w; });
        for (int i = 0; i < M; i++) {
            if (merge(edge[i].u, edge[i].v)) {
                cost += edge[i].w;
            }
        }
        printf("%d\n", cost);
    }
}