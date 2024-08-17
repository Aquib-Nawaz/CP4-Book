#include <iostream>
#include <cstring>
using namespace std;

int dp[20000], arr[100];
int main(){
    int T,n,v;
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&v,&n);
        int mx = 0;
        for (int i=0;i<n;i++) scanf("%d",&arr[i]),mx=max(mx,arr[i]);
        memset(dp,-1, sizeof dp);
        dp[0]=0;
        for (int i=0;i<n;i++){
            for (int j=v+mx-1;j>=arr[i];j--){
                if(dp[j-arr[i]]==-1)continue;
                if(dp[j]==-1)dp[j]=dp[j-arr[i]]+1;
                else dp[j]=min(dp[j],dp[j-arr[i]]+1);
            }
        }
        for(;dp[v]==-1;v++);
        printf("%d %d\n",v, dp[v]);
    }
}