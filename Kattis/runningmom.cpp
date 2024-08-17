#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <unordered_map>
using namespace std;

vector<int>adjL[10000];
int vis[10000];
unordered_map<string,int>mp;
char lineu[31], linev[31];

bool dfs(int u){
    vis[u]=0;
    bool ret=false;
    for(int v:adjL[u]){
        if(vis[v]==-1 )ret|=dfs(v);
        else if(vis[v]!=1)ret=true;
    }
    vis[u]=1+ret;
    return ret;
}

int main(){
    int M, N=0, u, v;
    scanf("%d", &M);
    memset(vis, -1, sizeof vis);
    for(int i=0;i<M;i++){
        scanf("%s%s", lineu, linev);
        if(mp.count(lineu)==0)mp[lineu]=N++;
        if(mp.count(linev)==0)mp[linev]=N++;
        adjL[mp[lineu]].push_back(mp[linev]);
    }

    for(int i=0;i<N;i++)if(vis[i]==-1)dfs(i);
    while(scanf("%s", lineu)!=-1){
        printf("%s %s\n", lineu, vis[mp[lineu]]==2?"safe":"trapped");
    }

}