#include <iostream>
#include <vector>
using namespace std;
bool vis[2][1001];
int cnt=0;
vector<int> adjL[2][1001];

void dfs1(int u){
    while(!vis[0][u]){
        vis[0][u]=true;
        if(adjL[1][u].empty()){cnt++;break;}
        u = adjL[1][u][0];
    }
}

void dfs2(){
    int u=1;
    while(!vis[1][u]){
        vis[1][u]=true;
        for(int v:adjL[0][u])
            dfs1(v);
        if(adjL[1][u].empty())break;
        u = adjL[1][u][0];
    }
}

int main(){
    int n,m;
    scanf("%d%d", &n,&m);
    for(int i=0;i<m;i++){
        int u,v;
        scanf("%d%d", &u,&v);
        adjL[u<0][abs(u)].push_back(v);
    }
    dfs1(1); dfs2();
    printf("%d",cnt);
}