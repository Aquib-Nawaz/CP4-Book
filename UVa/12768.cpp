#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dist[100];
bool inqueue[100];
vector<pair<int,int>>adjL[100];

int main(){
    int n,m,u,v,w;
    while (scanf("%d%d", &n, &m)==2 && n){
        for(int i=0;i<n;i++)adjL[i].clear(), dist[i]=1e9;
        for(int i=0;i<m;i++){
            scanf("%d%d%d", &u, &v, &w);
            u--,v--;
            adjL[u].push_back({v,-w});
        }
        queue<int>q[2];
        q[0].push(0);
        dist[0]=0;
        for(int i=0,x;i<n;i++){
            x=i&1;
            for(int j=0;j<n;j++)inqueue[j]= false;
            while (!q[x].empty()){
                u=q[x].front();
                q[x].pop();
                for(auto p:adjL[u]){
                    v=p.first;
                    w=p.second;
                    if (dist[v]>dist[u]+w){
                        dist[v]=dist[u]+w;
                        if(!inqueue[v])
                            q[1-x].push(v), inqueue[v]=true;
                    }
                }
            }
        }
        if(!q[n&1].empty())printf("Unlimited!\n");
        else {
            int ans=0;
            for(int i=0;i<n;i++)ans=max(ans,-dist[i]);
            printf("%d\n", ans);
        }
    }
}