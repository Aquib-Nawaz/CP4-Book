#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <utility>

using namespace std;
#define MAX 100001
#define MAXV 1000001
#define LG 18
vector<pair<int, int>>adj[MAX];
int height[MAX];
int parent[MAX][LG];
int mind[MAX][LG];
int maxd[MAX][LG];
int lg;

void dfs(int p, int u, int w){
    if(p!=-1){
        height[u]=height[p]+1;
        parent[u][0]=p;
        maxd[u][0]=w;
        mind[u][0]=w;
    }
    else{
        height[u]=0;
    }
    for(int i=1;i<=lg&&parent[u][i-1]!=-1;i++){
        parent[u][i]=parent[parent[u][i-1]][i-1];
        maxd[u][i]=max(maxd[u][i-1],maxd[parent[u][i-1]][i-1]);
        mind[u][i]=min(mind[u][i-1],mind[parent[u][i-1]][i-1]);
    }
    for(pair<int, int> v:adj[u]){
        if(v.first!=p){
            dfs(u,v.first,v.second);
        }
    }
}

int lca(int a,int b){
    if(height[a]<height[b]){
        swap(a,b);
    }
    int diff=height[a]-height[b];
    for(int i=lg;i>=0;i--){
        if(diff&(1<<i)){
            a=parent[a][i];
        }
    }
    if(a==b){
        return a;
    }
    for(int i=lg;i>=0;i--){
        if(parent[a][i]!=-1&&parent[a][i]!=parent[b][i]){
            a=parent[a][i];
            b=parent[b][i];
        }
    }
    return parent[a][0];
}

int minv(int a, int b){
    int diff = height[a]-height[b];
    int ans = MAXV;
    for(int i=lg;i>=0;i--){
        if(diff&(1<<i)){
            ans = min(ans,mind[a][i]);
            a=parent[a][i];
        }
    }
    return ans;
}

int maxv(int a, int b){
    int diff = height[a]-height[b];
    int ans = 0;
    for(int i=lg;i>=0;i--){
        if(diff&(1<<i)){
            ans = max(ans,maxd[a][i]);
            a=parent[a][i];
        }
    }
    return ans;
}



int main(){
    int N;
    scanf("%d",&N);
    lg=ceil(log2(N));
    memset(parent,-1,sizeof(parent));
    memset(maxd,0,sizeof(parent));
    fill_n(&mind[0][0],MAX*LG,MAXV);

    for(int i=1;i<N;i++){
        int a,b,w;
        scanf("%d %d %d",&a,&b,&w);
        adj[a].push_back({b,w});
        adj[b].push_back({a,w});
    }

    int root=1;

    dfs(-1,root,-1);
    int Q;
    scanf("%d",&Q);
    while(Q--){
        int a,b;
        scanf("%d %d",&a,&b);
        int l=lca(a,b);
        int minValue = min(minv(a,l),minv(b,l));
        int maxValue = max(maxv(a,l),maxv(b,l));
        printf("%d %d\n",minValue,maxValue);
    }
}