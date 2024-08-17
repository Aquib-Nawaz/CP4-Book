#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int,int>>adjL[10000];
struct Edge{int u,v,w;}edge[250000];
int dis[2][10000],N;
priority_queue<pair<int,int>>pq;

void djikstara(int u,int _v, int dist[]){
    int d;
    while(!pq.empty())pq.pop();
    pq.emplace(0,u);
    dist[u]=0;
    while(!pq.empty()){
        u=pq.top().second, d=-pq.top().first;
        pq.pop();
        if(dist[u]<d)continue;
        if(u==_v)return;
        for(auto v:adjL[u]){
            if(dist[v.first]>d+v.second){
                dist[v.first]=d+v.second;
                pq.emplace(-dist[v.first],v.first);
            }
        }
    }

}

int main(){
    int M,u;
    scanf("%d%d", &N, &M);
    for(int i=0;i<N;i++)dis[0][i]=dis[1][i]=1e9;
    for(int i=0;i<M;i++){
        int v,w;
        scanf("%d%d%d", &u,&v,&w);
        adjL[u].emplace_back(v,w);
        adjL[v].emplace_back(u,w);
        edge[i]={u,v,w};
    }
    djikstara(0, N-1, dis[0]);
    djikstara(N-1, 0, dis[1]);
    int ans=0, d=dis[1][0];
    for(int i=0;i<M;i++) {
        if (dis[0][edge[i].u] + dis[1][edge[i].v] + edge[i].w == d)ans += 2 * edge[i].w;
        if (dis[0][edge[i].v] + dis[1][edge[i].u] + edge[i].w == d)ans += 2 * edge[i].w;
    }
    printf("%d\n", ans);
}