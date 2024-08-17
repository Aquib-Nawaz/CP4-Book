#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<int>adjL[2][50];
int x, order[50],c,curCC, cc[50];
bool vis[50], indeg[50], outdeg[50];
pair<int,int>edge[1500];

void dfs(int u){
    vis[u]=true;
    if(x==1)
        cc[u]=curCC;
    for(auto v:adjL[x][u]){
        if(!vis[v])dfs(v);
        else if(x==1 && cc[v]!=curCC) outdeg[cc[v]]=indeg[curCC]=true;
    }
    if(x==0)order[--c]=u;
}

int main(){
    int N,M,u,v,C=0;
    while(scanf("%d%d", &N, &M)!=-1){
        for(int i=0;i<N;i++){
            vis[i]=indeg[i]=outdeg[i]=false; adjL[0][i].clear(); adjL[1][i].clear();
        }
        for(int i=0;i<M;i++){
            scanf("%d %d",&u,&v);
            adjL[0][u].push_back(v);
            adjL[1][v].push_back(u);
            edge[i] = {u,v};
        }
        x=0, c=N;
        for(int i=0;i<N;i++)if(!vis[i]) dfs(i);
        for(int i=0;i<N;i++)vis[i]  = false;
        x=1,curCC=0;
        for(int i=0;i<N;i++)if(!vis[order[i]]) dfs(order[i]), curCC++;
        int ans=0;
        printf("Case %d: ", ++C);
        if(curCC==1){
            printf("valid\n");
            continue;
        }
        bool invalid=true, f=true;
        u=v=-1;
        for(int i=0;i<curCC;i++)if(!indeg[i])u=(u==-1)?i:-2;
        for(int i=0;i<curCC;i++)if(!outdeg[i])v=(v==-1)?i:-2;
        if(u==0 && v==curCC-1){
            for(int i=0; i<M; i++){
                if(cc[edge[i].first]==0 && cc[edge[i].second]==curCC-1){
                    f=invalid;
                    if(invalid)u=edge[i].first,v=edge[i].second;
                    invalid=false;
                }
            }
        }
        if(curCC==2 && f)invalid=true;
        if(invalid)
            printf("invalid\n");
        else
            printf("%d %d\n", u,v);
    }
}
