#include <iostream>
#include <algorithm>
using namespace std;

int par[2000];
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
}edge[2000000];

int main(){
    int T,N,M,C,tot;
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &C,&N);
        M = N*(N-1)/2;
        for(int i=0;i<N;i++)par[i]=-1;
        for(int i=0;i<M;i++){
            scanf("%d%d%d", &edge[i].u,&edge[i].v,&edge[i].w);
        }
        sort(edge,edge+M,[](Edge &a,Edge &b){return a.w<b.w;});
        tot=N;
        for(int i=0;i<M;i++){
            if(merge(edge[i].u,edge[i].v)){
                tot+=edge[i].w;
            }
        }
        printf("%s\n", tot<=C?"yes":"no");
    }
}