#include <iostream>
#include <cstring>
using namespace std;

bool graph[100][100], val[100][100], vis[100][100];
int R,C,M,N, dir[4][2]={{1,-1}, {1,1}, {-1,1},{-1,-1}},
dirz[4][2]={{1,0},{0,1} ,{-1,0},{0,-1}};

bool valid(int r, int c){
    return r<R && c<C && r>=0 && c>=0 && !graph[r][c];
}

void dfs(int r, int c);

void tryNeighbour(int r, int c, int n, int m, int _dir[][2]=dir){
    int nr, nc;
    for(int i=0;i<4;i++){
        nr = r+_dir[i][0]*n;
        nc = c+_dir[i][1]*m;
        if(valid(nr,nc) ){
            val[r][c]^=1;
            if(!vis[nr][nc])
                dfs(nr,nc);
        }
    }
}

void dfs(int r, int c){
    vis[r][c]= true;
    if(N==M)
        tryNeighbour(r,c,N,N);
    else if(N==0 || M==0){
        int nonz = max(N,M);
        tryNeighbour(r,c,nonz,nonz, dirz);
    }
    else
        tryNeighbour(r,c,N,M), tryNeighbour(r,c,M,N);
}

int main(){
    int T,k,x,y,CN=0;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d%d%d", &R, &C, &M, &N,&k);
        memset(graph,0,sizeof(graph));
        memset(val,0,sizeof(val));
        memset(vis,0,sizeof(vis));
        for(int i=0;i<k;i++){
            scanf("%d%d",&x,&y);
            graph[x][y]=1;
        }

        dfs(0,0);

        int even=0,odd=0;
        for(int i=0;i<R;i++)for(int j=0;j<C;j++){
            if(graph[i][j] || !vis[i][j])continue;
            even+= !val[i][j];
            odd+= val[i][j];
        }
        printf("Case %d: %d %d\n", ++CN,even,odd);
    }
}