#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<pair<int,int>>adjL[100];
int dist[100], dp[100][100];
bool valid[100];

void djikstra(int u1, int v1){
    priority_queue<pair<int,int>>pq;
    if(!valid[u1] || !valid[v1])return;
    pq.push({0,u1});
    dist[u1]=0;
    while(!pq.empty()){
        pair<int,int>u=pq.top();
        pq.pop();
        if(!valid[u.second])continue;
        if(-u.first!=dist[u.second])continue;
        if(u.second==v1)return;
        for(auto v:adjL[u.second]){
            if(dist[v.second]>-u.first+v.first){
                dist[v.second]=-u.first+v.first;
                pq.push({-dist[v.second],v.second});
            }
        }
    }
}

int main(){
    int N,M,u1,v1,u2,v2;
    while(scanf("%d%d%d%d%d%d", &N,&M,&u1,&v1,&u2,&v2)==6){
        for(int i=0;i<N;i++)dist[i]=1e5, adjL[i].clear(), valid[i]=true;
        for(int i=0;i<N;i++){for(int j=0;j<N;j++)dp[i][j]=1e5; dp[i][i]=0;}
        u1--,u2--,v1--,v2--;

        for(int i=0;i<M;i++){
            int u,v,w;
            scanf("%d%d%d", &u,&v,&w);
            u--,v--;
            adjL[u].push_back({w,v});
            adjL[v].push_back({w,u});
            dp[u][v]=dp[v][u]=w;
        }

        for(int k=0;k<N;k++)
            for(int i=0;i<N;i++)
                for(int j=0;j<N;j++)
                    dp[i][j]=min(dp[i][j], dp[i][k]+dp[k][j]);

        valid[u1]=valid[v1]=false;
        for(int i=0;i<N;i++){
            for(auto v:adjL[i]){
                if(dp[u1][i] + v.first + dp[v.second][v1] == dp[u1][v1]){
                    valid[i]=valid[v.second]= false;
                }
            }
        }

        djikstra(u2,v2);

        if(dist[v2]==1e5){
            printf("MISSION IMPOSSIBLE.\n");
        }
        else {
            printf("%d\n", dist[v2]);
        }
    }
}