#include <iostream>
using namespace std;
int dp[10201];
struct cloth{
    int w, v;
}arr[102];
int main(){
    int m,n;
    while(scanf("%d%d",&m,&n)!=-1){
        for(int i=0;i<n;i++)scanf("%d%d", &arr[i].w, &arr[i].v);
        if(m>1800)m+=200;
        for(int i=0;i<=m;i++)dp[i]=-1e9;
        dp[0]=0;
        for(int i=0;i<n;i++){
            for(int j=m;j>=arr[i].w;j--){
                if(dp[j-arr[i].w]==-1)continue;
                dp[j]=max(dp[j],dp[j-arr[i].w]+arr[i].v);
            }
        }
        int ans=0;
        if(m<=1800) {
            for (int i = 0; i <= m; i++)ans = max(ans, dp[i]);
        }
        else {
            for(int i=2001; i<=m;i++)ans=max(ans, dp[i]);
            for(int i=0;i<=m-200;i++)ans=max(ans,dp[i]);
        }
        printf("%d\n",ans);

    }
}