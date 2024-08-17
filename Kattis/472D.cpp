#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> adj; // adjacency matrix of graph
const int INF = 1000000001; // weight INF means there is no edge
#define MAX 2001
vector<int>nadj[MAX];
long long dist[MAX][MAX];
struct Edge {
    int w = INF, to = -1;
};

void prim() {
    int total_weight = 0;
    vector<bool> selected(n, false);
    vector<Edge> min_e(n);
    min_e[0].w = 0;

    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!selected[j] && (v == -1 || min_e[j].w < min_e[v].w))
                v = j;
        }

        selected[v] = true;
        total_weight += min_e[v].w;
        if (min_e[v].to != -1){
            nadj[min_e[v].to].push_back(v);
            nadj[v].push_back(min_e[v].to);
        }

        for (int to = 0; to < n; ++to) {
            if (adj[v][to] < min_e[to].w)
                min_e[to] = {adj[v][to], v};
        }
    }
}

void dfs(int p, int u, int m){
    if(p!=-1)
        dist[m][u]=dist[u][m] = dist[m][p]+adj[u][p];
    else
        dist[m][u]=0;

    for(int v:nadj[u]){
        if(v!=p){
            dfs(u,v,m);
        }
    }
}


int main(){

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        adj.push_back(vector<int>());
        for(int j=0;j<n;j++){
            int w;
            scanf("%d",&w);
            adj[i].push_back(w);
            if((i==j&&w!=0)||(i!=j&&w==0)){
                printf("NO\n");
                return 0;
            }
        }
    }
    prim();
    for(int i=0;i<n;i++){
        dfs(-1,i,i);
    }
    for(int i=0;i<n;i++){
        for(int j=0; j<n; j++){
            if(dist[i][j]!=adj[i][j]){
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
}