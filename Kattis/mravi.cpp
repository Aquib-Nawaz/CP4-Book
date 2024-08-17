#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long double ld;
struct Edge{
    int v,w;
    bool t;
};
ld dp[1001];
vector<struct Edge>adjL[1001];
int V[1001];
ld dfs(int u){
    if(V[u]!=-1)return V[u];
    if(dp[u]>=0)return dp[u];
    ld cur=0;
    for(auto v:adjL[u]){
        ld req = dfs(v.v);
        if(v.t)req = sqrt(req);
        req*=ld(100)/v.w;
        cur=max(cur,req);
    }
    return dp[u]=cur;
}

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N-1; ++i) {
        int x, y, z, t;
        scanf("%d %d %d %d", &x, &y, &z, &t);
        adjL[x].push_back({y, z, t==1});
    }

    for (int i = 1; i <= N; ++i) {
        scanf("%d", &V[i]); dp[i]=-1;
    }

    printf("%.10Lf\n", dfs(1));
}