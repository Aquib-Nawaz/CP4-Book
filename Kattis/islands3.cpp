#include <iostream>
using namespace std;


int N,M, ans=0,dir[][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char graph[50][51];

bool inRange(int x, int y){
    return x >= 0 && x < N && y >= 0 && y < M && graph[x][y]!='W';
}

void dfs(int x, int y){
    graph[x][y] = 'W';
    int nx,ny;
    for(auto i:dir){
        nx = x + i[0], ny = y + i[1];
        if(inRange(nx,ny))dfs(nx,ny);
    }
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < N; i++)scanf("%s", graph[i]);
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(graph[i][j]=='L')ans++,dfs(i,j);
        }
    }
    printf("%d\n", ans);
}