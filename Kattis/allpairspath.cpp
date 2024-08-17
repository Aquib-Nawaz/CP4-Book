#include <iostream>
using namespace std;

int dp[150][150];
#define inf 1e6
int main(){
    int n,m,q;
    while(scanf("%d%d%d",&n,&m,&q),n){
        for(int i=0;i<n;i++){for(int j=0;j<n;j++)dp[i][j]=inf;dp[i][i]=0;}
        for(int i=0;i<m;i++){
            int u,v,w;
            scanf("%d%d%d", &u,&v,&w);
            dp[u][v]=min(dp[u][v], w);
        }
        for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)
            if(dp[i][k]!=inf&&dp[k][j]!=inf)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
        for(int k=0;k<n;k++)if(dp[k][k]<0)for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(dp[i][k]!=inf&&dp[k][j]!=inf)
            dp[i][j]=-inf;
        while(q--){
            int x,y;
            scanf("%d%d",&x,&y);
            if(dp[x][y]==inf)printf("Impossible\n");
            else if(dp[x][y]==-inf)printf("-Infinity\n");
            else printf("%d\n",dp[x][y]);
        }
        printf("\n");
    }
}