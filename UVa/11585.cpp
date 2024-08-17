#include <iostream>
#include <cstring>
using namespace std;

char graph[100][101],l,w;
bool vis[100][100];
int N,M;

struct triplet{
    int x,y,v;
}arr[10000];

bool inRange(int r, int &c){
    return c<M&&c>=0&& r<N && r>=0 && !vis[r][c] && graph[r][c]==l;
}

int dir[4][2]={{0,-1},{-1,0},{0,1},{1,0}},
dir2[4][2]={{-1,-1},{1,-1},{-1,1},{1,1}},
dir3[4][2] = {{0,0},{0,1},{1,1},{1,0}};

int dfs(int r, int c,int type=0){
    vis[r][c]=true;
    int ret=1;
    for(auto & i : dir){
        int nr = r+i[0], nc = c+i[1];
        if(inRange(nr,nc) )ret+=dfs(nr,nc,type);
    }
    if(type)
        for(auto &i:dir2){
            int nr = r+i[0], nc = c+i[1];
            if(inRange(nr,nc))dfs(nr,nc,type);
        }
    return ret;
}

int main(){
    int d,T;
    bool solve,f;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d%d",&N,&M,&d);
        for(int i=0;i<d;i++)scanf("%d %d %d",&arr[i].x,&arr[i].y,&arr[i].v);
        for(int i=0;i<N;i++)scanf("%s",graph[i]);
        solve=true;
        memset(vis,0,sizeof vis);
        //condition 1
        f=true;
        l='#';
        for(int i=0;i<N;i++)for(int j=0;j<M;j++){
            if(graph[i][j]=='#' && !vis[i][j]){
                if(f){
                    f=false;
                    dfs(i,j);
                }
                else{
                    solve=false;
                    break;
                }
            }
        }
        if(!solve){
            printf("not solved\n");
            continue;
        }
        memset(vis,0,sizeof vis);

        //condition 2
        l='.';
        for(int i=0;i<d;i++)if(graph[arr[i].x][arr[i].y]!='.' ||
        vis[arr[i].x][arr[i].y] || dfs(arr[i].x,arr[i].y)!=arr[i].v){
            solve=false;
            break;
        }
        for(int i=0;i<N;i++)for(int j=0;j<M;j++)if(!vis[i][j]&&graph[i][j]=='.')solve=false;

        if(!solve){
            printf("not solved\n");
            continue;
        }
        //condition 3

        memset(vis,0,sizeof vis);
        for(int i=0;i<N;i++){
            if(!vis[i][0] && graph[i][0]=='.')dfs(i,0,1);
            if(!vis[i][M-1] && graph[i][M-1]=='.')dfs(i,M-1,1);
        }
        for(int i=0;i<M;i++){
            if(!vis[0][i] && graph[0][i]=='.')dfs(0,i,1);
            if(!vis[N-1][i] && graph[N-1][i]=='.')dfs(N-1,i,1);
        }
        for(int i=0;i<N;i++)for(int j=0;j<M;j++){
            if(graph[i][j]=='.' && !vis[i][j]){
                solve=false;
                break;
            }
        }
        if(!solve){
            printf("not solved\n");
            continue;
        }
        //condition 4
        for(int i=0;i<N-1;i++)for(int j=0;j<M-1;j++){
            f=false;
            for(auto k:dir3){
                f|=graph[i+k[0]][j+k[1]]=='.';
            }
            if(!f){
                solve=false;
                break;
            }
        }
        if(!solve){
            printf("not solved\n");
            continue;
        }
        printf("solved\n");
    }
}