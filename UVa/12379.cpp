#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

vector<int>adjL[10001];
int dist[10001],n;
int findFurthest(int u){
    queue<int>q;
    q.push(u);
    memset(dist,-1,sizeof dist);
    dist[u]=0;
    while (!q.empty()){
        u=q.front();
        q.pop();
        for(int v:adjL[u]){
            if(dist[v]==-1){
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }

    return u;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d", &n);
        for(int i=0;i<n;i++)adjL[i].clear();
        for(int i=0;i<n;i++){
            int d,v;
            scanf("%d",&d);
            while (d--)
                scanf("%d", &v),adjL[i].push_back(v-1);
        }
        int ans=2*(n-1);
        int x = findFurthest(0);
        int y = findFurthest(x);
        ans-=dist[y];
        printf("%d\n", ans);
    }
}