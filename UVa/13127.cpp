#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

vector<pair<int,int>>adjL[1000];
int dist[1000];
bool Bank[1000];
priority_queue<pair<int,int>>pq;

void djikstara(){
    int u,d;
    while(!pq.empty()){
        u=pq.top().second, d=-pq.top().first;
        pq.pop();
        if(dist[u]<d)continue;
        for(auto v:adjL[u]){
            if(dist[v.first]>d+v.second){
                dist[v.first]=d+v.second;
                pq.emplace(-dist[v.first],v.first);
            }
        }
    }

}

int main(){
    int N,M,P,B,u;
    while(scanf("%d%d%d%d", &N,&M,&B,&P)!=-1){
        for(int i=0;i<N;i++)adjL[i].clear(), dist[i]=1e9, Bank[i]= false;
        for(int i=0;i<M;i++){
            int v,w;
            scanf("%d%d%d", &u,&v,&w);
            adjL[u].emplace_back(v,w);
            adjL[v].emplace_back(u,w);
        }
        for(int i=0;i<B;i++)scanf("%d", &u), Bank[u]= true;
        for(int i=0;i<P;i++)scanf("%d", &u), dist[u]=0, pq.emplace(0,u);
        djikstara();
        int mx=0,cnt=0;
        for(int i=0;i<N;i++){
            if(!Bank[i])continue;
            if(mx<dist[i]){
                mx=dist[i];
                cnt=1;
            }
            else if(mx==dist[i])cnt++;
        }
        printf("%d ", cnt);
        if(mx==1e9)printf("*\n");
        else printf("%d\n", mx);
        for(int i=0;i<N;i++){
            if(Bank[i] &&mx==dist[i]){
                printf("%d", i);
                if(--cnt)printf(" ");
            }
        }
        printf("\n");
    }
}