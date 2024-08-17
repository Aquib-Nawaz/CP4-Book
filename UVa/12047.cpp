#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

int dist[2][10000];
vector<pair<int,int>>adjL[2][10000];
struct Edge{
    int u,v,w;
} edge[100000];

void djikstra(int s, int x){
    priority_queue<pair<int,int>>pq;
    pq.emplace(0,s);
    dist[x][s]=0;
    int d;
    while(!pq.empty()){
        s=pq.top().second;
        d=-pq.top().first;
        pq.pop();
        if(dist[x][s]!=d)continue;
        for(pair<int,int>v:adjL[x][s]){
            if(dist[x][v.first]>dist[x][s]+v.second){
                dist[x][v.first]=dist[x][s]+v.second;
                pq.emplace(-dist[x][v.first],v.first);
            }
        }
    }
}

int main(){
    int T,N,M,s,t,p;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d%d%d",&N,&M,&s,&t,&p);
        s--,t--;
        for(int i=0;i<N;i++)for(int k=0;k<2;k++)adjL[k][i].clear(), dist[k][i]=1e9;
        for(int i=0;i<M;i++){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            a--,b--;
            edge[i]={a,b,c};
            adjL[0][a].push_back({b,c});
            adjL[1][b].push_back({a,c});
        }
        djikstra(s,0);
        djikstra(t,1);
        if(dist[0][t]>p)printf("-1\n");
        else {
            sort(edge, edge+M, [](Edge &a, Edge &b){return a.w>b.w;});
            int ans=0;
            for(int i=0;i<M;i++){
                if(dist[0][edge[i].u]+edge[i].w+dist[1][edge[i].v]<=p){
                    ans=edge[i].w;
                    break;
                }
            }
            printf("%d\n", ans);
        }
    }
}