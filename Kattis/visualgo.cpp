#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int,int>>adjL[10000];
int dist[10000], dp[10000];
int main(){
    int N,M,u,v,w,t;
    scanf("%d%d", &N,&M);
    for(int i=0;i<N;i++){
        dp[i]=0;
        dist[i]=1e7;
    }
    for (int i=0;i<M;i++){
        scanf("%d%d%d", &u,&v,&w);
        adjL[u].push_back({v,w});
    }
    scanf("%d%d", &u,&t);
    dist[u]=0;
    dp[u]=1;
    priority_queue<pair<int,int>>pq;
    pq.emplace(0,u);
    while(!pq.empty()) {
        int d = -pq.top().first;
        u = pq.top().second;
        pq.pop();
        if (dist[u] < d)continue;
        if (d > dist[t])break;
        for (auto it: adjL[u]) {
            v = it.first, w = it.second;
            if (d + w < dist[v]) {
                dist[v] = d + w;
                dp[v] = dp[u];
                pq.emplace(-dist[v], v);
            } else if (d + w == dist[v]) {
                dp[v] += dp[u];
            }
        }
    }
    printf("%d\n", dp[t]);
}