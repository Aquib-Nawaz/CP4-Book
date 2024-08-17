#include <iostream>
#include <utility>
#include <queue>
#include <map>
using namespace std;

char g[30][30];
int N,M, dist[30][30];
int dir[][2]={{-1,0},{1,0},{0,-1},{0,1}};
map<pair<int,int>,pair<int,pair<int,int>>>mp;
bool inqueue[30][30];

bool inRange(int x, int y){
    return x>=0 && x<N && y>=0 && y<M && g[x][y]!='#' ;
}

int bfm(int ui, int uj, int vi, int vj){
    queue<pair<int,int>>q[2];
    q[0].push({ui,uj});
    dist[ui][uj] = 0;
    for(int i=0;i<N*M;i++){
        int x=i&1;
        for(int j=0;j<N;j++)for(int k=0;k<M;k++)inqueue[j][k]= false;
        while(!q[x].empty()){
            int _x = q[x].front().first;
            int _y = q[x].front().second;
            q[x].pop();
            if(_x==vi && _y==vj)continue;
            if(mp.count({_x,_y})){
                auto it=mp[{_x,_y}];
                if(dist[it.second.first][it.second.second]>dist[_x][_y]+it.first){
                    dist[it.second.first][it.second.second] = dist[_x][_y]+it.first;
                    if(!inqueue[it.second.first][it.second.second])
                        q[x^1].push({it.second.first,it.second.second}), inqueue[it.second.first][it.second.second] = true;
                }
                continue;
            }
            for(auto & d : dir){
                int nx = _x+d[0];
                int ny = _y+d[1];
                if(inRange(nx,ny) && dist[nx][ny] > dist[_x][_y]+1){
                    dist[nx][ny] = dist[_x][_y]+1;
                    if(!inqueue[nx][ny])
                        q[x^1].push({nx,ny}), inqueue[nx][ny] = true;
                }
            }
        }
    }
    if(!q[N*M&1].empty())return -1e8;//Never
    return dist[vi][vj];
}

int main(){
    int u,v,k;
    while(scanf("%d%d", &N,&M), N){
        scanf("%d",&k);
        mp.clear();
        for(int i=0;i<N;i++)for(int j=0;j<M;j++)g[i][j]='.', dist[i][j] = 1e8, inqueue[i][j] = false;
        for(int i=0;i<k;i++){
            scanf("%d%d", &u,&v);
            g[u][v]='#';
        }
        scanf("%d", &k);
        for(int i=0;i<k;i++){
            int a,b,c;
            scanf("%d%d%d%d%d", &u,&v,&a,&b,&c);
            mp[{u,v}]={c,{a,b}};
        }
        int ans = bfm(0,0,N-1,M-1);
        if(ans==-1e8)printf("Never\n");
        else if(ans==1e8) printf("Impossible\n");
        else printf("%d\n", ans);
    }
}