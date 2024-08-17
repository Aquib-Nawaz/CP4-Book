#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int R,C,dist[1000][1000], dir[][2]={{-1,0},{-1,1},{0,1},{1,1},
        {1,0},{1,-1},{0,-1},{-1,-1}};
char g[1001][1001];
int bfs(){
    int r1,c1,r2,c2;
    scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    r1--,c1--,r2--,c2--;
    deque<pair<int,int>> q;
    q.push_back({r1,c1});
    fill (dist[0], dist[0]+1000*1000, 1e9);
    dist[r1][c1]=0;

    int x,y,dx,dy;
    while(!q.empty()) {
        x = q.front().first, y = q.front().second;
        q.pop_front();
        if (x == r2 && y == c2)break;
        for (int i=0;i<8;i++) {
            dx = x + dir[i][0], dy = y + dir[i][1];
            if (dx >= 0 && dx < R && dy >= 0 && dy < C && dist[dx][dy] > dist[x][y]+(g[x][y]!=i) ) {
                dist[dx][dy] = dist[x][y] + (g[x][y]!=i);
                g[x][y]==i?q.emplace_front(dx,dy):q.emplace_back(dx,dy);
            }
        }
    }
    return dist[r2][c2];
}

int main(){
    scanf("%d%d", &R, &C);
    for(int i=0;i<R;i++){
        scanf("%s", g[i]);
        for(int j=0;j<C;j++)
            g[i][j]-='0';
    }
    int n;
    scanf("%d", &n);
    while(n--){
        printf("%d\n",bfs());
    }
}