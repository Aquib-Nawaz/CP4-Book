#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long double ld;

int par[750];
int Find(int x){if(par[x]==-1) return x; return par[x]=Find(par[x]);}
void Union(int x,int y){par[Find(x)]=Find(y);}
bool cycle(int x, int y){return Find(x)==Find(y);}

ld dist(ld x1, ld y1, ld x2, ld y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

struct Edge{
    int u,v; ld w;
    bool const operator < (const Edge& rhs) const{
        return w < rhs.w;
    }
} edge[300000];
ld Nx[750], Ny[750];
int main() {
    int T, M;
    scanf("%d", &T);
    while (T--) {
        int n;
        M=0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            par[i]=-1;
            scanf("%Lf %Lf",Nx+i,Ny+i);
            for(int j=0;j<i;j++){
                edge[M++] = { i, j, dist(Nx[i], Ny[i], Nx[j], Ny[j]) };
            }
        }
        sort(edge, edge+M);
        ld ans=0;
        for(int i=0; i<M;i++){
            if(!cycle(edge[i].u, edge[i].v)){
                ans+=edge[i].w;
                Union(edge[i].u, edge[i].v);
            }
        }
        printf("%Lf\n", ans);
    }
}