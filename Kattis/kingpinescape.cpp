#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int>adjL[100001], res;
void dfs(int u, int p){
    bool isLeave=true;
    for(int v:adjL[u]){
        if(v!=p)dfs(v,u), isLeave=false;
    }
    if(isLeave)
        res.push_back(u);
}

int main(){
    int N,u,v,K;
    scanf("%d%d", &N,&K);
    for(int i=0;i<N-1;i++){
        scanf("%d%d",&u,&v);
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }
    dfs(K,-1);
    if(adjL[K].size()==1)res.push_back(K);
    int tot=(res.size()+1)/2;
    int add=res.size()/2;
    printf("%d\n", tot);
    for(int i=0;i<tot;i++)printf("%d %d\n", res[i], res[(add+i)%res.size()]);
}

