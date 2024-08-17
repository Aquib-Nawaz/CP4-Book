#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int dist[100], V[100];
vector<int>adjL[1000];
bool inqueue[100];

int main(){
    int n;
    while(scanf("%d", &n),n!=-1){
        for(int i=0;i<n;i++){
            dist[i]=-1e8, adjL[i].clear();
            int d,u;
            scanf("%d%d", V+i, &d);
            for(int j=0;j<d;j++){
                scanf("%d", &u);
                u--;
                adjL[i].push_back(u);
            }
        }
        queue<int>pq[2];
        pq[0].push(0);
        dist[0]=100;
        for(int i=0;i<n;i++){
            int x=i&1;
            for(int j=0;j<n;j++)inqueue[j]=false;
            while (!pq[x].empty()){
                int u=pq[x].front();
                pq[x].pop();
                for(auto v:adjL[u]){
                    if(dist[v]<dist[u]+V[v] && dist[u]+V[v]>0){
                        dist[v]=dist[u]+V[v];
                        if(!inqueue[v])
                            inqueue[v]=true,pq[1-x].push(v);
                    }
                }
            }
        }
        int x=n&1;
        while(!pq[x].empty()){
            int u=pq[x].front();
            dist[u]=1e8;
            pq[x].pop();
            for(auto v:adjL[u]){
                if(!inqueue[v])
                    inqueue[v]=true,pq[x].push(v);
            }
        }
        if(dist[n-1]>=-100)printf("winnable\n");
        else printf("hopeless\n");
    }
}