#include <iostream>
#include <vector>
using namespace std;
int C,P,X,L;
vector<int>adjL[200001];
int Part[200001][2];
bool vis[200001];

bool dfs(int u){
    if(u==X)return true;
    vis[u]=true;
    for(auto v:adjL[u]){
        if(vis[v])continue;
        Part[v][1]++;
        if(Part[v][1]>=(Part[v][0]+1)/2)
            if(dfs(v))return true;
    }
    return false;
}

int main() {
    scanf("%d%d%d%d",&C,&P,&X,&L);
    int u,v;
    for(int i=1;i<=C;i++)Part[i][0]=Part[i][1]=0,vis[i]=false;

    for(int i=0;i<P; i++){
        scanf("%d%d",&u,&v);
        adjL[u].push_back(v);
        adjL[v].push_back(u);
        Part[u][0]++;
        Part[v][0]++;
    }

    if(dfs(L))printf("leave");
    else printf("stay");
}