#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long double ld;

int par[3][1000];
int Find(int s, int x){if(par[s][x]==-1) return x; return par[s][x]=Find(s, par[s][x]);}
bool Union(int s, int x,int y){x=Find(s, x); y=Find(s, y); if(x==y)return false; par[s][x]=y; return true;}
bool cycle(int s , int x, int y){return Find(s, x)==Find(s, y);}

ld dist(ld x1, ld y1, ld x2, ld y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

struct Edge{
    int u,v; ld w;
    bool operator < (const Edge& rhs) const{
        return w < rhs.w;
    }
} edge[500000];

int Nx[1000], Ny[1000];

int main() {
    int T, M, R, u, v, C=0;
    scanf("%d", &T);
    while (T--) {
        int n;
        M=0;
        scanf("%d%d", &n, &R);
        memset(par,-1,sizeof par);
        for (int i = 0; i < n; i++) {
            scanf("%d %d",Nx+i,Ny+i);
            for(int j=0;j<i;j++){
                edge[M] = { i, j, dist(Nx[i], Ny[i], Nx[j], Ny[j]) };
                if(R-edge[M].w >-1e-10)Union(0, i, j);
                M++;
            }
        }
        sort(edge, edge+M);
        int ns=0;
        for(int i=0;i<n;i++)if(par[0][i]==-1)ns++;
        ld ans1=0, ans2=0;
        for(int i=0; i<M;i++){
            u = edge[i].u, v = edge[i].v;
            if(!cycle(0, u, v)){
                u = Find(0, u), v = Find(0, v);
                if(Union(1, u, v)) ans2+=edge[i].w;
                continue;
            }
            if(Union(2, u, v))
                ans1 += edge[i].w;
        }
        printf("Case #%d: %d %d %d\n",++C, ns, int(round(ans1)), int(round(ans2)));
    }
}