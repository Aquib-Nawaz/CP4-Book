#include <iostream>
using namespace std;

char name[13];
int g[120][15][15];
typedef long long ll;
ll dp[2][15];
int main(){
    int n,m;
    while (scanf("%s", name)==1){
        scanf("%d%d", &n,&m);
        for(int k=0;k<n-1;k++){
            for(int i=0;i<m;i++){
                for(int j=0;j<m;j++){
                    scanf("%d", &g[k][i][j]);
                }
            }
        }
        printf("%s\n", name);
        for(int i=0;i<m;i++)dp[0][i]=0;
        for(int i=0;i<n-1;i++){
            int x=i&1;
            for(int j=0;j<m;j++){
                ll cur=1e18;
                for(int k=0;k<m;k++){
                    cur=min(cur,dp[x][k]+g[i][k][j]);
                }
                dp[x^1][j]=cur+2;
            }
        }
        ll cur = 1e18;
        for(int i=0;i<m;i++)cur=min(cur,dp[n-1&1][i]);
        printf("%lld\n", cur);
    }
}