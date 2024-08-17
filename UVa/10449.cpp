#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

vector<pair<int,int>>adjL[200];
int dist[200], V[200];
bool inqueue[200];
int main(){
    int n,m,Q,C=0;
    while (scanf("%d", &n) == 1){
        for(int i=0;i<n;i++){
            adjL[i].clear();
            dist[i]=1e8;
            inqueue[i]= false;
            scanf("%d", V+i);
        }
        scanf("%d", &m);
        for(int i=0;i<m;i++){
            int a,b,c;
            scanf("%d%d", &a,&b);
            a--,b--;
            c=(V[b]-V[a]);
            adjL[a].push_back({b,c*c*c});
        }
        queue<int>q[2];
        q[0].push(0);
        dist[0]=0;
        for(int i=0,x;i<n;i++){
            x=i&1;
            while(!q[x].empty()){
                int u=q[x].front();
                q[x].pop();
                for(auto v:adjL[u]){
                    if(dist[v.first]>dist[u]+v.second){
                        dist[v.first]=dist[u]+v.second;
                        if(!inqueue[v.first])
                            q[x^1].push(v.first), inqueue[v.first]=true;
                    }
                }
            }
            for(int j=0;j<n;j++)inqueue[j]= false;
        }
        int x=n&1;
        while(!q[x].empty()){
            int u=q[x].front();
            q[x].pop();
            dist[u]=-1;
            for(auto v:adjL[u]){
                if(!inqueue[v.first]){
                    q[x].push(v.first);
                    inqueue[v.first]=true;
                }
            }
        }
        scanf("%d", &Q);
        printf("Set #%d\n", ++C);
        for(int i=0;i<Q;i++){
            int u;
            scanf("%d", &u);
            u--;
            if(dist[u]<3||dist[u]==1e8)
                printf("?\n");
            else
                printf("%d\n", dist[u]);
        }
    }
}