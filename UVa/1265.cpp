#include <iostream>
#include <unordered_set>
using namespace std;

int par[5000], size[5000];
int find(int x){return par[x]==-1?x:par[x]=find(par[x]);}
bool merge(int x, int y){x = find(x),y= find(y); if(x==y) return false; par[x]=y; size[y]+=size[x]; return true;}
struct {
    int x,y,w;
}edge[12500000];

int toConsider[5000];

int main(){
    int T,N,M;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d", &N, &M);
        for(int i = 0; i < N; i++) par[i] = -1, size[i] = 1;
        for(int i = 0; i < M; i++) {
            scanf("%d%d%d", &edge[i].x, &edge[i].y, &edge[i].w);
            edge[i].x--, edge[i].y--;
        }
        sort(edge, edge+M, [](const auto &a, const auto &b){return a.w > b.w;});
        int ans = 0;
        unordered_set<int>vis;
        for(int i = 0,c=0; i < M; i++){
            if(merge(edge[i].x, edge[i].y))
                toConsider[c++] = edge[i].x;
            if(i<M && edge[i].w==edge[i+1].w)
                continue;
            for(int j=0;j<c;j++){
                int u = find(toConsider[j]);
                if(!vis.count(u)){
                    ans+=size[u];
                    vis.insert(u);
                }
            }
            c=0;
            vis.clear();
        }
        printf("%d\n", ans);
    }
}