#include <iostream>
using namespace std;

int dp[100][100];
int main(){
    int T,n,m,C=0;
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &n, &m);
        for(int i=0;i<n;i++){for(int j=0;j<n;j++)dp[i][j]=100; dp[i][i]=0;}
        for(int i=0;i<m;i++){
            int u,v;
            scanf("%d%d", &u,&v);
            dp[u][v]=dp[v][u]=1;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
                }
            }
        }
        int ans=0,s,d;
        scanf("%d%d", &s,&d);
        for(int i=0;i<n;i++)
            ans = max(ans,dp[s][i]+dp[i][d]);
        printf("Case %d: %d\n", ++C, ans);
    }
}