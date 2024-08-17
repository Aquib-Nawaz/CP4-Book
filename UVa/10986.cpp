#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<pair<int,int>>adjL[20000];
int E, dist[20000];
int djikstra(int u){
    priority_queue<pair<int,int>>pq;
    dist[u]=0;
    pq.emplace(0,u);
    while(!pq.empty()){
        int d=-pq.top().first;
        u=pq.top().second;
        pq.pop();
        if(d>dist[u])continue;
        if(u==E)return d;
        for(auto v:adjL[u]){
            if(dist[v.first]>d+v.second){
                dist[v.first]=d+v.second;
                pq.emplace(-dist[v.first],v.first);
            }
        }
    }
    return -1;
}

int main(){
    int T,N,M,S,C=0;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d%d", &N,&M, &S, &E);
        for(int i=0;i<N;i++)adjL[i].clear(), dist[i]=2e9;
        for(int i=0;i<M;i++){
            int a,b,w;
            scanf("%d%d%d", &a,&b,&w);
            adjL[a].emplace_back(b, w);
            adjL[b].emplace_back(a, w);
        }
        int ans=djikstra(S);
        printf("Case #%d: ", ++C);
        if(ans==-1)printf("unreachable\n");
        else printf("%d\n", ans);
    }
}