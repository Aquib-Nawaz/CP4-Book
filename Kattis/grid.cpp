#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;

int N,M, dist[500][500], dir[][2]={{-1,0},{1,0},{0,-1},{0,1}};
char g[500][500];
int main(){
    scanf("%d%d", &N,&M);
    for(int i=0;i<N;i++)scanf("%s", g[i]), memset(dist[i], -1, sizeof(int)*M);
    queue<pair<int,int>>q;

    dist[0][0]=0;
    q.emplace(0,0);
    while(!q.empty()){
        int x=q.front().first, y=q.front().second;
        q.pop();
        if(x==N-1&&y==M-1)break;
        int d = g[x][y]-'0';
        for(auto& i:dir){
            int xx=x+i[0]*d, yy=y+i[1]*d;
            if(xx<0||yy<0||xx>=N||yy>=M||dist[xx][yy]!=-1)continue;
            dist[xx][yy]=dist[x][y]+1;
            q.emplace(xx,yy);
        }
    }
    printf("%d\n", dist[N-1][M-1]);
}