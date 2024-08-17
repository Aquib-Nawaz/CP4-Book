#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;

ll dist[100][100];
vector<pair<int,int>> adjL[100];
bool vis[100];
int main(){
    int C,S,Q, u,v, w, cas=0;
    while(scanf("%d%d%d", &C,&S,&Q),C){
        for(int i = 0; i < C; i++){
            adjL[i].clear();
            for(int j = 0; j < C; j++){
                dist[i][j] = 1e18;
            }
        }
        for(int i = 0; i < S; i++){
            scanf("%d%d%d", &u, &v, &w);
            u--,v--;
            adjL[u].emplace_back(v,w);
            adjL[v].emplace_back(u,w);
        }
        // Djikstara from every node as source
        for(int i = 0; i < C; i++){
            dist[i][i] = 0;
            priority_queue<pair<int,int>> pq;
            for(int j=0;j<C;j++)vis[j]=false;
            pq.emplace(0,i);
            int rem=C;
            while(!pq.empty()){
                u = pq.top().second;
                pq.pop();
                if(vis[u]) continue;
                vis[u]= true;
                if(--rem==0)break;

                for(auto it : adjL[u]){
                    v=it.first, w=it.second;
                    if(!vis[v] && dist[i][v] > max(dist[i][u], (ll)w)){
                        dist[i][v] = max(dist[i][u], (ll)w);
                        pq.emplace(-dist[i][v], v);
                    }
                }
            }
        }
        if(cas)printf("\n");
        printf("Case #%d\n", ++cas);
        while(Q--){
            scanf("%d%d", &u, &v);
            u--,v--;
            if(dist[u][v]==1e18)
                printf("no path\n");
            else
                printf("%lld\n", dist[u][v]);
        }

    }

}