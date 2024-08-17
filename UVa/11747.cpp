#include <iostream>
#include <algorithm>
using namespace std;

int par[1000];
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
}edge[25000];

int main(){
    int N,M;
    while (scanf("%d%d", &N,&M),N){
        for(int i=0;i<N;i++)par[i]=-1;
        for(int i=0;i<M;i++){
            scanf("%d%d%d", &edge[i].u,&edge[i].v,&edge[i].w);
        }
        sort(edge,edge+M,[](Edge &a,Edge &b){return a.w<b.w;});
        bool f=true;
        for(int i=0;i<M;i++){
            if(!merge(edge[i].u,edge[i].v)){
                if(!f)printf(" ");
                printf("%d",edge[i].w);
                f=false;
            }
        }
        if(f)printf("forest");
        printf("\n");
    }
}