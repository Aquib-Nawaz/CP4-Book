#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int,int>>adjL[10001];
int dist[10001];
bool safe[10001];
int main(){
    int n,m,a,k,u,v,w;
    while(scanf("%d%d%d%d", &n,&m,&a,&k),n){
        for(int i=0;i<n;i++)dist[i]=1e6, safe[i]=true, adjL[i].clear();
        for(int i=0;i<m;i++){
            scanf("%d%d%d", &u,&v,&w);
            u--,v--;
            adjL[u].push_back({v,w});
            adjL[v].push_back({u,w});
        }
        priority_queue<pair<int,int>>pq;
        int cnt=n;
        for(int i=0;i<a;i++){
            scanf("%d", &u);
            u--;
            pq.push({0,u});
            dist[u]=0;
            if(cnt!=0)
                while(!pq.empty()){
                    u=pq.top().second;
                    w=-pq.top().first;
                    pq.pop();
                    if(w!=dist[u])continue;
                    if(safe[u])cnt--, safe[u]= false;
                    for(auto v:adjL[u]){
                        if(dist[v.first]>w+v.second && w+v.second<k){
                            dist[v.first]=w+v.second;
                            pq.push({-dist[v.first],v.first});
                        }
                    }
                }
            while(!pq.empty())pq.pop();
            printf("%d\n", cnt);
        }
        printf("\n");
    }
}