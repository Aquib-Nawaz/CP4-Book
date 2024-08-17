#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

vector<pair<int,int>>adjL[10000];
int dist[10000];

void djikstra(int u){
    dist[u]=0;
    priority_queue<pair<int,int>>q;
    q.emplace(0,u);
    int d;
    while(!q.empty()){
        d = -q.top().first, u=q.top().second;
        q.pop();
        if(d!=dist[u])continue;
        for(auto& v:adjL[u]){
            if(dist[v.first]>d+v.second){
                dist[v.first]=d+v.second;
                q.emplace(-dist[v.first],v.first);
            }
        }
    }
}

int main(){
    int n,m,q,s;
    bool f= true;
    while(scanf("%d%d%d%d", &n,&m, &q,&s),n){
        for(int i=0;i<n;i++)adjL[i].clear(), dist[i]=1e9;
        for(int i=0;i<m;i++){
            int a,b,c;
            scanf("%d%d%d", &a,&b,&c);
            adjL[a].emplace_back(b,c);
        }
        for(int i=0;i<n;i++)dist[i]=1e9;
        djikstra(s);
        if(!f)printf("\n");
        else f=false;
        for(int i=0;i<q;i++){
            int a;
            scanf("%d", &a);
            if(a>=n||dist[a]==1e9)printf("Impossible\n");
            else printf("%d\n", dist[a]);
        }
    }
}