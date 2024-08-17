#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAXN 15

char E[MAXN];
int idx[26],N, curarr[MAXN+1], l;
vector<int> adj[MAXN];
bool vis[MAXN][1<<MAXN];

bool solve(int cur, int mask){
    if(cur==N-1){
        if(mask==(1<<N)-1)
            return true;
        return false;
    }
    if(vis[cur][mask]) return false;
    vis[cur][mask] = true;
    for(int i : adj[cur]){
        if((mask&(1<<i))==0){
            curarr[l]=i;
            l++;
            if(solve(i, mask|(1<<i))){
                return true;
            }
            l--;
        }
    }
    return false;
}

int main(){
    int T,M,C=0;
    scanf("%d",&T);
    char u,v;
    while(T--){
        scanf("%d %d",&N,&M);
        for (int i = 0; i < N; ++i) scanf(" %c",E+i), idx[E[i]-'A'] = i, adj[i].clear();
        for (int i = 0; i < M; ++i) {
            scanf(" %c %c",&u, &v);
            adj[idx[u-'A']].push_back(idx[v-'A']);
            adj[idx[v-'A']].push_back(idx[u-'A']);
        }
        for(int i=0;i<N;i++)sort(adj[i].begin(), adj[i].end(), [&](int a, int b)
        {return E[a]<E[b];});
        for(int i=0;i<N;i++)memset(vis[i], 0, sizeof vis[i]) ;
        curarr[0]=0;
        l=1;
        bool f = solve(0, 1);
        printf("Case %d: ", ++C);
        if(!f)printf("impossible\n");
        else {
            for(int i=0;i<N;i++)printf("%c",E[curarr[i]]);
            printf("\n");
        }
    }
}