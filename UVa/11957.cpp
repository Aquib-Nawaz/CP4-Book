#include <iostream>
using namespace std;

char g[100][101];
int dp[100][100], dir[2]={-1,1},n;

bool inRange(int x, int y){
    return !(y<0 || x<0 || y>=n);
}

int dfs(int x, int y){
    if(x==0)return 1;
    if(dp[x][y]!=-1)return dp[x][y];
    dp[x][y]=0;
    for(int d:dir){
        int nx = x-1, ny=y+d;
        if(!inRange(nx,ny))
            continue;
        if(g[nx][ny]=='B')
            nx-=1,ny+=d;
        if(inRange(nx,ny) && g[nx][ny]!='B')
            dp[x][y]=(dp[x][y]+dfs(nx,ny))%1000007;
    }
    return dp[x][y];
}

int main(){
    int T,C=0;
    scanf("%d", &T);
    char c;
    while(T--){
        scanf("%d", &n);
        int ui,uj;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf(" %c", &c);
                g[i][j] = c;
                if(c=='W')ui=i,uj=j;
                dp[i][j] = -1;
            }
        }
        printf("Case %d: %d\n", ++C, dfs(ui,uj));
    }
}