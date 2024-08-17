#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <unordered_set>
using namespace std;

unordered_set<int>adjL[2501];
int dist[2501], par[2][2501];

int findFurthest(int u, int pa[]= nullptr){
    queue<int>q;
    q.push(u);
    memset(dist, -1, sizeof dist);
    dist[u]=0;
    if(pa)pa[u]=-1;
    while (!q.empty()){
        u=q.front();
        q.pop();
        for(int v:adjL[u]){
            if(dist[v]==-1){
                dist[v]=dist[u]+1;
                q.push(v);
                if(pa)
                    pa[v]=u;
            }
        }
    }
    return u;
}
int diameter(int u, int p=1){
    int x = findFurthest(u);
    return findFurthest(x, par[p]);
}

int myceil(int x){
    return x/2+(x&1);
}

int centre(int x, int v){
    for(int i=0;i<v/2;i++)x=par[1][x];
    return x;
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N-1;i++){
        int u,v;
        scanf("%d %d", &u,&v);
        adjL[u].insert(v);
        adjL[v].insert(u);
    }
    int y = diameter(1,0);
    int ans=dist[y],v, idx[4];
    while(par[0][y]!=-1){
        v = par[0][y];
        adjL[y].erase(v);
        adjL[v].erase(y);
        int d1= diameter(y), v1 = dist[d1], c1= centre(d1 , dist[d1]),
            d2 = diameter(v),v2= dist[d2], c2=centre(d2 , dist[d2]);
        int diam = max(max(v1,v2), myceil(v1)+ myceil(v2)+1);
        if(diam<ans){
            ans=diam;
            idx[0]=y,idx[1]=v;
            idx[2]=c1,idx[3]=c2;
        }
        adjL[y].insert(v);
        adjL[v].insert(y);
        y=v;
    }
    printf("%d\n%d %d\n%d %d\n", ans, idx[0], idx[1], idx[2], idx[3]);
}