#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int dist[1000];
vector<pair<int,int>>adjL[1000];
bool inqueue[1000];

int main(){
    int n,m,q,s;
    bool f=true;
    while(scanf("%d%d%d%d", &n,&m,&q,&s),n){
        for(int i=0;i<n;i++)dist[i]=1e8, adjL[i].clear();
        for(int i=0;i<m;i++){
            int a,b,c;
            scanf("%d%d%d", &a,&b, &c);
            adjL[a].push_back({b,c});
        }
        queue<int>pq[2];
        pq[0].push(s);
        dist[s]=0;
        for(int i=0;i<n;i++){
            int x=i&1;
            for(int j=0;j<n;j++)inqueue[j]=false;
            while (!pq[x].empty()){
                int u=pq[x].front();
                pq[x].pop();
                for(auto v:adjL[u]){
                    if(dist[v.first]>dist[u]+v.second){
                        dist[v.first]=dist[u]+v.second;
                        if(!inqueue[v.first])
                            inqueue[v.first]=true,pq[1-x].push(v.first);
                    }
                }
            }
        }
        int x=n&1;
        while(!pq[x].empty()){
            int u=pq[x].front();
            dist[u]=-1e8;
            pq[x].pop();
            for(auto v:adjL[u]){
                if(!inqueue[v.first])
                    inqueue[v.first]=true,pq[x].push(v.first);
            }
        }
        if(!f)printf("\n");
        else f=false;
        for (int i=0;i<q;i++) {
            scanf("%d", &s);
            if(dist[s]==-1e8)
                printf("-Infinity\n");
            else if(dist[s]==1e8)
                printf("Impossible\n");
            else
                printf("%d\n", dist[s]);
        }
    }
}