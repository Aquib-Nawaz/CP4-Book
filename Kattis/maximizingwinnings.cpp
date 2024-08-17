#include <iostream>
using namespace std;
int g[50][50], dp[2][2][50];
int main(){
    int n,m,x;
    while(scanf("%d", &n),n){
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d", g[i]+j);
        scanf("%d", &m);
        if(m==0){
            printf("0 0\n");
            continue;
        }
        for(int i=0;i<n;i++)dp[0][0][i]=dp[0][1][i]=g[0][i];
        x=1;
        for(int i=0;i<m-1;i++){
            x=i&1;
            for(int j=0;j<n;j++){
                int mn=1e9,mx=0;
                for(int k=0;k<n;k++){
                    mn=min(mn,dp[x][1][k]+g[k][j]);
                    mx=max(mx,dp[x][0][k]+g[k][j]);
                }
                dp[x^1][0][j]=mx;
                dp[x^1][1][j]=mn;
            }
        }
        x^=1;
        int mx=0,mn=1e9;
        for(int i=0;i<n;i++)mx=max(mx,dp[x][0][i]),mn=min(mn,dp[x][1][i]);
        printf("%d %d\n",mx,mn );
    }
}