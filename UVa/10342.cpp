#include <iostream>
using namespace std;

struct Edge{
    int u,v,w;
}arr[5000];
int dp[100][100];

int main(){
    int n,m,C=0;
    while (scanf("%d%d", &n,&m)==2){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) dp[i][j]=100000;
            dp[i][i]=0;
        }
        for(int i=0;i<m;i++){
            scanf("%d%d%d", &arr[i].u,&arr[i].v,&arr[i].w);
            dp[arr[i].u][arr[i].v]=arr[i].w;
            dp[arr[i].v][arr[i].u]=arr[i].w;
        }
        for(int k=0;k<n;k++)for(int i=0;i<n;i++)for(int j=0;j<n;j++)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
        int q;
        scanf("%d", &q);
        printf("Set #%d\n", ++C);
        while(q--){
            int u,v;
            scanf("%d%d", &u,&v);
            if(dp[u][v]==100000) printf("?\n");
            else {
                int ans=100000;
                for(int i=0;i<m;i++){
                    int t = dp[u][arr[i].u]+arr[i].w+dp[arr[i].v][v];
                    if(t>dp[u][v] )ans = min(t,ans);
                    t = dp[u][arr[i].v]+arr[i].w+dp[arr[i].u][v];
                    if(t>dp[u][v] )ans = min(t,ans);
                }
                if(ans!=100000)printf("%d\n", ans);
                else
                    printf("?\n");
            }
        }
    }
}