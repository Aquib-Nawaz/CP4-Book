#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<int>adj[1001];
int height[1001];
int parent[1001][11];
bool vis[1001];

void dfs(int p, int u){
    if(p!=-1)
        height[u]=height[p]+1;
    else
        height[u]=0;
    parent[u][0]=p;
    for(int i=1;i<11&&parent[u][i-1]!=-1;i++){
        parent[u][i]=parent[parent[u][i-1]][i-1];
    }
    for(int v:adj[u]){
        if(v!=p){
            dfs(u,v);
        }
    }
}

int main(){
    int n,C;
    scanf("%d",&n);

    for(C=1;C<=n;C++){
        int N;
        scanf("%d",&N);
        memset(parent,-1,sizeof(parent));
        fill(vis, vis+1001, false );
        for(int i=1;i<=N;i++){
            adj[i].clear();
            int a,b;
            scanf("%d",&a);
            for(int j=0;j<a;j++){
                scanf("%d",&b);
                vis[b]=true;
                adj[i].push_back(b);
                adj[b].push_back(i);
            }
        }
        int root=1;
        for(int i=1;i<=N;i++){
            if(!vis[i]){
                root=i;
                break;
            }
        }
        dfs(-1,root);
        int Q;
        scanf("%d",&Q);
        printf("Case %d:\n",C);
        while(Q--){
            int a,b;
            scanf("%d %d",&a,&b);
            if(height[a]<height[b]){
                swap(a,b);
            }
            int diff=height[a]-height[b];
            for(int i=10;i>=0;i--){
                if(diff&(1<<i)){
                    a=parent[a][i];
                }
            }
            if(a==b){
                printf("%d\n",a);
                continue;
            }
            for(int i=10;i>=0;i--){
                if(parent[a][i]!=-1&&parent[a][i]!=parent[b][i]){
                    a=parent[a][i];
                    b=parent[b][i];
                }
            }
            printf("%d\n",parent[a][0]);
        }
    }
}