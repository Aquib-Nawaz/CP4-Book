#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <bitset>
using namespace std;

#define MAX 450001
#define LG 20

vector<int>adj[MAX];
int height[MAX];
int parent[MAX][LG];
int shade[MAX];
int lg;
bitset<251> shades[MAX];

void dfs(int p, int u){
    if(p!=-1)
        height[u]=height[p]+1;
    else
        height[u]=0;
    shades[u].reset();
    shades[u][shade[u]]=true;
    parent[u][0]=p;
    for(int i=1;i<=lg&&parent[u][i-1]!=-1;i++){
        parent[u][i]=parent[parent[u][i-1]][i-1];
    }
    for(int v:adj[u]){
        if(v!=p){
            dfs(u,v);
            shades[u]|=shades[v];
        }
    }
}

int main(){
    int n,C;
    scanf("%d",&n);
    int N,root,Q;
    for(C=1;C<=n;C++){
        scanf("%d %d %d",&N, &Q, &root);
        lg = ceil(log2(N));
        memset(parent,-1,sizeof(parent));

        for(int i=0;i<N;i++){
            scanf("%d",&shade[i]);
            adj[i].clear();
        }

        for(int i=0;i<N-1;i++){
            int a,b;
            scanf("%d %d",&a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        dfs(-1,root);

        while(Q--){
            int a,b;
            scanf("%d %d",&a,&b);
            if(height[a]<height[b]){
                swap(a,b);
            }
            int diff=height[a]-height[b];
            for(int i=lg;i>=0;i--){
                if(diff&(1<<i)){
                    a=parent[a][i];
                }
            }
            int lca ;
            if(a==b){
                lca=a;
            }
            else{
                for(int i=lg;i>=0;i--){
                    if(parent[a][i]!=-1&&parent[a][i]!=parent[b][i]){
                        a=parent[a][i];
                        b=parent[b][i];
                    }
                }
                lca=parent[a][0];
            }
            printf("%d\n",(int)shades[lca].count());
        }
    }
}