#include <iostream>
#include <vector>
using namespace std;

int order[10001],c,N,x;
vector<int>adjL[10001];
bool vis[10001];
void dfs(int u){
    vis[u]=true;
    for(auto v:adjL[u]){
        if(!vis[v])dfs(v);
    }

    if(x==0)
        order[--c]=u;
}

int main(){
    int M,u,v,T,C=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d", &N,&M);
        for(int i=1;i<=N;i++){
            vis[i]=false, adjL[i].clear();
        }
        c=N;
        for(int i=0;i<M;i++){
            scanf("%d%d", &u,&v);
            adjL[u].push_back(v);
        }
        x=0;
        for(int i=1;i<=N;i++)if(!vis[i])dfs(i);
        for(int i=1;i<=N;i++)vis[i]= false;
        int ans=0;
        x=1;
        for(int i=0;i<N;i++)if(!vis[order[i]])ans++, dfs(order[i]);
        printf("Case %d: %d\n", ++C, ans);
    }
}
