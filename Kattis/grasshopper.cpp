#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int dir[][2]={{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2},
               {1,-2}, {-1,2}, {-1,-2}};
int N,M,dist[101][101];

int bfs(int r1, int c1, int r2, int c2){
    queue<pair<int,int>> q;
    for(int i=1;i<=N;i++)for(int j=1;j<=M;j++)dist[i][j]=-1;
    q.emplace(r1,c1);
    dist[r1][c1] = 0;
    while(!q.empty()){
        int r = q.front().first, c = q.front().second;
        q.pop();
        if(r2==r && c2==c) break;
        for(auto & i:dir){
            int nr = r+i[0], nc = c+i[1];
            if(nr<=0 || nr>N || nc<=0 || nc>M || dist[nr][nc]!=-1) continue;
            dist[nr][nc] = dist[r][c]+1;
            q.emplace(nr,nc);
        }
    }
    return dist[r2][c2];
}

int main(){
    int r1,c1,r2,c2;
    while(scanf("%d%d%d%d%d%d", &N,&M,&r1,&c1,&r2,&c2)!=-1){
        int ans=bfs(r1,c1,r2,c2);
        if(ans==-1)printf("impossible\n");
        else printf("%d\n", ans);
    }
}