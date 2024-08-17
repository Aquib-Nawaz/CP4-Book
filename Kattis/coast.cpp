#include <iostream>
using namespace std;


int graph[1002][1002],N,M, ans=0,dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool inRange(int x, int y){
    return x >= 0 && x <= N+1 && y >= 0 && y <= M+1 && graph[x][y]!=-1;
}

void dfs(int x, int y){
    graph[x][y] = -1;
    int nx,ny;
    for(auto i:dir){
        nx = x + i[0], ny = y + i[1];
        if(inRange(nx,ny)){
            if(graph[nx][ny]==1)ans++;
            else dfs(nx,ny);
        }
    }

}
int main() {
    char c;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)for (int j = 1; j <= M; j++)scanf(" %c", &c), graph[i][j] = c == '1';
    for(int i=0;i<=N+1;i++)graph[i][0]=graph[i][M+1]=0;
    for(int i=0;i<=M+1;i++)graph[0][i]=graph[N+1][i]=0;
    dfs(0,0);
    printf("%d\n", ans);
}