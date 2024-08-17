#include <iostream>
using namespace std;

bool graph[1001][1001];
int vis[1001][1001],v,N,M,cnter=0, dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool inRange(int x, int y){
    return x >= 1 && x <= N && y >= 1 && y <= M && vis[x][y]==-1 && graph[x][y]==v;
}

void dfs(int x, int y){
    vis[x][y] = cnter;
    int nx,ny;
    for(auto i:dir){
        nx = x + i[0], ny = y + i[1];
        if(inRange(nx,ny)){
            dfs(nx,ny);
        }
    }

}
int main() {
    int q, x, y,u;
    char c;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)for (int j = 1; j <= M; j++)scanf(" %c", &c), graph[i][j] = c == '1', vis[i][j] = -1;
    for (int i = 1; i <= N; i++)for (int j = 1; j <= M; j++)if (vis[i][j] == -1)v = graph[i][j], dfs(i, j), cnter++;
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d%d%d", &x, &y,&u,&v);
        if (vis[x][y] == vis[u][v]){
            printf("%s\n", !graph[x][y]?"binary":"decimal");
        }
        else{
            printf("neither\n");
        }
    }
}