#include <iostream>
#include <algorithm>
using namespace std;

int par[2501];
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
}edge[3200000];

int main(){
    int N,M=0,w;
    scanf("%d", &N);
    for(int i=1;i<=N;i++)par[i]=-1;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            scanf("%d", &w);
            if(j>i)edge[M++]={i,j,w};
        }
    }
    sort(edge,edge+M,[](Edge &a,Edge &b){return a.w<b.w;});
    for(int i=0;i<M;i++){
        if(merge(edge[i].u,edge[i].v)){
            printf("%d %d\n", edge[i].u, edge[i].v);
        }
    }
}