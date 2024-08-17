#include <iostream>
#include <queue>
#include <cmath>
#include <utility>
#include <limits>
#include <stack>
using namespace std;

pair<int,int>nodes[2503];
int par[2503];
double dist[2503];
#define EPS 1e-10
double _dist(int u, int v){
    return pow(nodes[u].first-nodes[v].first,2.0)+pow(nodes[u].second-nodes[v].second,2.0);
}

void djikstra(int n){
    priority_queue<pair<double,int>>pq;
    int u = n;
    pq.emplace(0,u);
    dist[u]=0;
    double d;
    while (!pq.empty()){
        u = pq.top().second;
        d = -pq.top().first;
        pq.pop();
        if(abs(d-dist[u])>EPS)continue;
        if(u==n-1)return;
        for(int v=1;v<=n;v++){
            if(u==v)continue;
            if(dist[v]>d+_dist(u,v)){
                dist[v] = d+_dist(u,v);
                par[v]=u;
                pq.emplace(-dist[v],v);
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    n+=2;
    for(int i=1;i<=n;i++){
        scanf("%d %d", &nodes[i].first, &nodes[i].second);
        dist[i]=numeric_limits<double>::max();
        par[i]=i;
    }
    djikstra(n);
    if(par[n-1]==n)printf("-\n");
    else {
        int u=par[n-1];
        while(u!=n)printf("%d\n", u-1), u=par[u];
    }
}