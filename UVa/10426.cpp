#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int dir1[][2]={{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2},
               {1,-2}, {-1,2}, {-1,-2}};

struct state{
    int i,j,t;
    state(int i, int j, int t):i(i),j(j),t(t){}
};

int dist[4][2][16][16], N,M, nodes[5][2];

void process(int nr, int nc, int t, int d, queue<state>&q, int dis[2][16][16]){
    if(nr<0 || nr>=N || nc<0 || nc>=M || dis[t][nr][nc]<=d+1) return;
    t |= nr==nodes[4][0] && nc==nodes[4][1];
    dis[t][nr][nc] = d+1;
    q.emplace(nr, nc, t);
}

void bfs(int r1, int c1, int dis[2][16][16]){
    queue<state> q;
    q.emplace(r1, c1, 0), dis[0][r1][c1] = 0;
    while(!q.empty()){
        int r = q.front().i, c = q.front().j, t=q.front().t;
        q.pop();
        int d = dis[t][r][c];
        for(auto & i : dir1){
            int nr = r+i[0], nc = c+i[1];
            process(nr, nc, t, d, q, dis);
        }
    }
}
char line[20];
int main(){
    while(scanf("%s%d%d", line,&N,&M)!=-1){
        for(auto & node : nodes)scanf("%d%d", node, node+1),node[0]--, node[1]--;
        for(auto &i: dist)for(auto &j: i)for(int k=0;k<N;k++)for(int l=0;l<M;l++)j[k][l]=1e6;
        for(int i=0;i<4;i++) bfs(nodes[i][0], nodes[i][1], dist[i]);
//        for(auto & i : dist){
//            for(int j=0;j<N;j++){
//                for(int k=0;k<M;k++)printf("%d ", i[0][j][k]);
//                printf("\n");
//            }
//            printf("\n");
//        }
        int ans=1e6,all;
        for(int i=0;i<N;i++)for(int j=0;j<M;j++){
            all=0;
            for(auto & k : dist)all+=k[0][i][j];
            ans=min(ans, all);
            for(auto & k: dist)ans = min(all-k[0][i][j]+k[1][i][j],ans);
        }
        printf("%s\n", line);
        if(ans>=1e6) printf("Meeting is impossible.\n");
        else printf("Minimum time required is %d minutes.\n", ans);
    }
}