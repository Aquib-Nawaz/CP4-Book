#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dist[25],n;
vector<int>adjL[25];

int findfurthest(int u, int v=-1){
    queue<int>q;
    for(int i=0;i<n;i++)dist[i]=-1;
    q.push(u);
    dist[u]=0;
    if(v!=-1)q.push(v), dist[v]=0;

    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int v:adjL[u]){
            if(dist[v]==-1){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    int re=0;
    for(int i=0;i<n;i++)if(dist[i]>re)re=dist[i];
    return re;
}
int main(){
    int m,T,C=0;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n,&m);
        for(int i=0;i<n;i++)adjL[i].clear();
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d", &a,&b);
            adjL[a].push_back(b);
            adjL[b].push_back(a);
        }
        int ans=n;
        for(int i=0;i<n;i++)ans = min(ans, 2*findfurthest(i));
        for(int i=0;i<n;i++){
            for(int v:adjL[i])
                if(i<v)ans = min(ans, findfurthest(i,v)*2+1);
        }
        printf("Case #%d:\n%d\n\n",++C, ans);
    }
}