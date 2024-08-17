#include <iostream>
#include <vector>
using namespace std;

vector<int>adjL[2][2001];
int x;
bool vis[2001];

void dfs(int u){
    vis[u]=true;
    for(auto v:adjL[x][u]){
        if(!vis[v])dfs(v);
    }

}

int main(){
    int N,M,u,v,p;
    while(scanf("%d%d", &N, &M),N){
        for(int i=0;i<N;i++){
            vis[i]=false; adjL[0][i].clear(); adjL[1][i].clear();
        }
        for(int i=0;i<M;i++){
            scanf("%d %d %d",&u,&v,&p);
            u--,v--;
            adjL[0][u].push_back(v);
            adjL[1][v].push_back(u);
            if(p==2)
                adjL[0][v].push_back(u), adjL[1][u].push_back(v);
        }
        x=0;
        dfs(0);
        bool ans=true;
        for(int i=0;i<N;i++)
            if(!vis[i]){
                ans=false;
                break;
            }
        if(ans){
            for(int i=0;i<N;i++)vis[i]= false;
             x=1;
             dfs(0);
            for(int i=0;i<N;i++)
                if(!vis[i]){
                    ans=false;
                    break;
                }
        }
        printf("%d\n",ans?1:0);
    }
}