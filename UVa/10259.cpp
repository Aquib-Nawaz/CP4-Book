#include <iostream>
using namespace std;
int g[100][100], dp[100][100],n,k;
int dir[][2] = {{0,-1}, {0,1},{1,0},{-1,0}};

int dfs(int x, int y){
    if(dp[x][y]!=-1)return dp[x][y];
    int ch=0,v=g[x][y];
    for(auto di:dir){
        int nx=x,ny=y;
        for(int i=1;i<=k;i++){
            nx+=di[0], ny+=di[1];
            if(nx<0 || ny<0 || nx>=n || ny>=n)break;
            if(g[nx][ny]>v && ch<dfs(nx,ny))
                ch= dfs(nx,ny);
        }
    }
    return dp[x][y]=ch+v;
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n,&k);
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d", g[i]+j), dp[i][j]=-1;
        int ans=dfs(0,0);

        printf("%d\n", ans);
        if(T)printf("\n");
    }
}