#include <iostream>
#include <queue>
using namespace std;

char box[3];
int dir1[][2]={{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2},
              {1,-2}, {-1,2}, {-1,-2}};
int dir2[][2]={{-2,2}, {2,2}, {2,-2}, {-2,-2}};

struct state{
    int i,j,t;
    state(int i, int j, int t):i(i),j(j),t(t){}
};

int dist[3][41][41], N;
bool vis[3][41][41];

void process(int nr, int nc, int t, int d, queue<state>&q){
    if(nr<0 || nr>=N || nc<0 || nc>=N || vis[t][nr][nc]) return;
    vis[t][nr][nc]= true;
    dist[t][nr][nc] = d+1;
    q.emplace(nr, nc, t);
}

int bfs(int r1, int c1, int r2, int c2){
    queue<state> q;
    for(int i=0;i<3;i++)q.emplace(r1, c1, i), dist[i][r1][c1] = 0, vis[i][r1][c1]=true;
    while(!q.empty()){
        int r = q.front().i, c = q.front().j, t=q.front().t;
        q.pop();
        int d = dist[t][r][c];
        if(r==r2 && c==c2) return d;
        if(t!=0)
            for(auto & i : dir1){
                int nr = r+i[0], nc = c+i[1];
                process(nr, nc, 0, d, q);
            }
        if(t!=1)
            for(auto & i : dir2){
                int nr = r+i[0], nc = c+i[1];
                process(nr, nc, 1, d, q);
            }
        if(t!=2){
            process(r,N-c-1,2,d,q);
            process(N-r-1,c,2,d,q);
        }
    }
    return -1;
}

int main(){
    int r1,c1,r2,c2,x,y;
    while(scanf("%d%d%d%d%d", &N, &r1, &c1, &r2,&c2),N){
        r1--,c1--,r2--,c2--;
        N<<=1;
        for(int i=0;i<N;i++)for(int j=0;j<N;j++)for(int k=0;k<3;k++)vis[k][i][j]=false;
        while(scanf("%d%d",&x,&y),x){
            x--,y--;
            vis[0][x][y]=vis[1][x][y]=vis[2][x][y]=true;
        }
        int ans=bfs(r1, c1, r2, c2);
        if(ans==-1)
            printf("Solution doesn't exist\n");
        else
            printf("Result : %d\n", ans);
    }
}