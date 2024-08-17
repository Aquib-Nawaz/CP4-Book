#include <iostream>
#include <vector>
using namespace std;
typedef vector<int>vi;

vi adjL[200001];
bool vis[200001];
void dfs(int u){
    vis[u]=1;
    for(int v : adjL[u]){
        if(!vis[v])dfs(v);
    }
}

int main(){
    int N,M, u, v;
    scanf("%d%d", &N,&M);
    for(int i=0;i<M;i++){
        scanf("%d%d",&u,&v);
        adjL[u].push_back(v);
        adjL[v].push_back(u);
    }
    dfs(1);
    bool f=1;
    for(int i=1;i<=N;i++){
        if(!vis[i]){
            f=0;
            printf("%d\n",i);
        }
    }
    if(f)printf("Connected\n");
}