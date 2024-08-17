#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int R,C, dir[][2] = {{0,-1},{-1,0},{0,1},{1,0}},
dist[1000][1000];
bool g[1000][1000];
bool valid(int r,int c){
    return r>=0 && r<R && c>=0 && c<C && !g[r][c];
}

int main(){
    int m,d, ur, uc, vr, vc;
    while(scanf("%d%d", &R,&C), R){
        scanf("%d", &m);
        for(int i=0;i<R;i++)for(int j=0;j<C;j++)g[i][j]= false;
        for(int i=0,r,c;i<m;i++){
            scanf("%d%d", &r,&d);
            while(d--)scanf("%d", &c), g[r][c]= true;
        }
        scanf("%d%d%d%d", &ur,&uc,&vr,&vc);
        queue<pair<int,int>>q;
        q.emplace(ur,uc);
        dist[ur][uc]=0;
        while(!q.empty()){
            int r=q.front().first, c=q.front().second;
            q.pop();
            g[ur][uc]= true;
            if(r==vr && c==vc)break;
            for(auto & i : dir){
                if(valid(r+i[0],c+i[1])){
                    q.emplace(r+i[0],c+i[1]);
                    g[r+i[0]][c+i[1]]= true;
                    dist[r+i[0]][c+i[1]]=dist[r][c]+1;
                }
            }
        }
        printf("%d\n", dist[vr][vc]);
    }
}