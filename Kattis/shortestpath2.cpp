#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int dist[10000];
struct Edge{
    int v,t,p,w;
    Edge(int v,int t,int p,int w):v(v),w(w),t(t),p(p){}
};
vector<Edge>adjL[10000];
#define MAX 1e9
void djikstra(int u){
    dist[u]=0;
    priority_queue<pair<int,int>>q;
    q.emplace(0,u);
    int d;
    while(!q.empty()){
        d = -q.top().first, u=q.top().second;
        q.pop();
        if(d!=dist[u])continue;
        int temp;
        for(auto& e:adjL[u]){
            temp = d+e.w;
            if(e.t>=d)temp+=e.t-d;
            else if(e.p==0)continue;
            else temp+=(e.p-(d-e.t)%e.p)%e.p;
            if(temp<dist[e.v]){
                dist[e.v]=temp;
                q.emplace(-temp,e.v);
            }
        }
    }
}

int main(){
    int n,m,q,s;
    bool f= true;
    while(scanf("%d%d%d%d", &n,&m, &q,&s),n){
        for(int i=0;i<n;i++)adjL[i].clear(), dist[i]=MAX;
        for(int i=0;i<m;i++){
            int a,b,c,d,e;
            scanf("%d%d%d%d%d", &a,&b,&c,&d,&e);
            adjL[a].emplace_back(b,c,d,e);
        }
        for(int i=0;i<n;i++)dist[i]=MAX;
        djikstra(s);
        if(!f)printf("\n");
        f=false;
        for(int i=0;i<q;i++){
            int a;
            scanf("%d", &a);
            if(a>=n||dist[a]==MAX)printf("Impossible\n");
            else printf("%d\n", dist[a]);
        }
    }
}