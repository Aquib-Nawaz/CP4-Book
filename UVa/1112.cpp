#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<pair<int,int>>adjL[101];
int t,E, dist[101];
bool djikstra(int u){
    priority_queue<pair<int,int>>pq;
    dist[u]=0;
    pq.emplace(0,u);
    while(!pq.empty()){
        int d=-pq.top().first;
        u=pq.top().second;
        pq.pop();
        if(d>t)return false;
        if(d>dist[u])continue;
        if(u==E)return true;
        for(auto v:adjL[u]){
            if(dist[v.first]>d+v.second){
                dist[v.first]=d+v.second;
                pq.emplace(-dist[v.first],v.first);
            }
        }
    }
    return false;
}

int main(){
    int T,N,M;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d%d", &N,&E, &t,&M);
        for(int i=1;i<=N;i++)adjL[i].clear();
        for(int i=0;i<M;i++){
            int a,b,w;
            scanf("%d%d%d", &a,&b,&w);
            adjL[a].emplace_back(b, w);
        }
        int ans=0;
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++)dist[j]=2e9;
            if(djikstra(i))ans++;
        }
        printf("%d\n", ans);
        if(T)printf("\n");
    }
}