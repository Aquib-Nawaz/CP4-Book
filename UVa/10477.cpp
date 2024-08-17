#include <iostream>
#include <queue>
using namespace std;

int dir1[][2]={{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2},
               {1,-2}, {-1,2}, {-1,-2}};
int dir2[][2]={{3,1}, {3,-1}, {-3,1}, {-3,-1}, {1,3},
               {1,-3}, {-1,3}, {-1,-3}};
int dir3[][2]={{0,1}, {0,-1}, {-1,0}, {1,0}};

struct state{
    int i,j,t;
    state(int i, int j, int t):i(i),j(j),t(t){}
};

int dist[3][20][20], N;

void process(int nr, int nc, int t, int d, queue<state>&q){
    if(nr<0 || nr>=N || nc<0 || nc>=N || dist[t][nr][nc]!=-1) return;
    dist[t][nr][nc] = d+1;
    q.emplace(nr, nc, t);
}

int bfs(int r1, int c1, int r2, int c2){
    queue<state> q;
    for(int i=0;i<3;i++)q.emplace(r1, c1, i), dist[i][r1][c1] = 0;
    while(!q.empty()){
        int r = q.front().i, c = q.front().j, t=q.front().t;
        q.pop();
        int d = dist[t][r][c];
        if(r==r2 && c==c2) return d;
        if(t==2)
            for(auto & i : dir1){
                int nr = r+i[0], nc = c+i[1];
                process(nr, nc, 0, d, q);
            }
        if(t==0)
            for(auto & i : dir2){
                int nr = r+i[0], nc = c+i[1];
                process(nr, nc, 1, d, q);
            }
        if(t==1){
            for(auto & i : dir3){
                int nr = r+i[0], nc = c+i[1];
                process(nr, nc, 2, d, q);
            }
            if(abs(r-r2)==1 && abs(c-c2)==1 && dist[2][r2][c2]==-1)dist[2][r2][c2]=d+1, q.emplace(r2,c2,2);
        }
    }
    return -1;
}

int main(){
    int r1,c1,r2,c2,x,y,S,C=0;
    while(scanf("%d%d", &N, &S),N){
        printf("Set %d:\n", ++C);
        while(S--){
            scanf("%d%d",&x,&y);
            --x,--y;
            r1 = x/N, c1=x%N, r2 = y/N, c2 = y%N;
            for(int i=0;i<N;i++)for(int j=0;j<N;j++)dist[0][i][j]=dist[1][i][j]=dist[2][i][j]=-1;
            x = bfs(r1,c1,r2,c2);
            if(x==-1)printf("?\n");
            else
                printf("%d\n", x);
        }
    }
}