#include <iostream>
using namespace std;
int n,c, cost[100][100], profit[100][50], dp[2][100], x;

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &n,&c);
        for(int i=0;i<n;i++)for(int j=0;j<c;j++)scanf("%d", profit[i]+j);
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d", cost[i]+j);
        for(int i=0;i<n;i++)dp[0][i]=profit[i][0];
        x=1;
        for(int i=0;i<c-1;i++){
            x=i&1;
            for(int j=0;j<n;j++){
                int cur=-1e9;
                for(int k=0;k<n;k++)cur = max(cur, dp[x][k]-cost[k][j]);
                dp[x^1][j] = cur+profit[j][i+1];
            }
        }
        x^=1;
        int ans=0;
        for(int i=0;i<n;i++)ans = max(ans, dp[x][i]);
        printf("%d\n", ans);
    }
}