#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

unordered_map<string,int>mp;
int order[1000],c,x,N;
vector<int>adjL[2][1000];
bool vis[1000];
char line[26];
void dfs(int u){
    vis[u]=true;
    for(auto v:adjL[x][u]){
        if(!vis[v])dfs(v);
    }

    if(x==0)
        order[--c]=u;
}

int main(){
    int M,u,v;
    while(scanf("%d%d", &N,&M),N){
        mp.clear();
        for(int i=0;i<N;i++){
            vis[i]=false, adjL[0][i].clear(), adjL[1][i].clear();
            scanf(" %[^\n]", line);
            mp[line]=i;
        }
        c=N;
        for(int i=0;i<M;i++){
            scanf(" %[^\n]", line);
            u=mp[line];
            scanf(" %[^\n]", line);
            v=mp[line];
            adjL[0][u].push_back(v);
            adjL[1][v].push_back(u);
        }
        x=0;
        for(int i=0;i<N;i++)if(!vis[i])dfs(i);
        for(int i=0;i<N;i++)vis[i]= false;
        x=1;
        int ans=0;
        for(int i=0;i<N;i++)if(!vis[order[i]])ans++, dfs(order[i]);
        printf("%d\n", ans);
    }
}
