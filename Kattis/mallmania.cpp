#include <iostream>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

int dist[2001][2001], dir[][2]={{-1,0},{1,0},{0,-1},{0,1}};
bool valid(int r, int c){
    return r>=0&&r<2001&&c>=0&&c<2001;
}
int main(){
    int x,y,x1,y1,N,M;
    while(scanf("%d", &N),N){
        queue<pair<int,int>>q;
        memset(dist, -1, sizeof dist);
        for(int i=0;i<N;i++)scanf("%d%d", &x,&y), dist[x][y]=0, q.emplace(x,y);
        scanf("%d", &M);
        for(int i=0;i<M;i++)scanf("%d%d", &x,&y), dist[x][y]=-2;
        int ans=-1;
        while(!q.empty()&&ans==-1){
            int r=q.front().first, c=q.front().second;
            q.pop();
            for(auto &i : dir){
                x1=r+i[0], y1=c+i[1];
                if(valid(x1,y1) ){
                    if(dist[x1][y1]>=0)continue;
                    if(dist[x1][y1]==-2)ans=dist[r][c]+1;
                    q.emplace(x1,y1);
                    dist[x1][y1]=dist[r][c]+1;
                }
            }
        }
        printf("%d\n",ans);
    }
}