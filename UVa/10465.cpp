#include <iostream>
#include <cstring>
using namespace std;

int arr[2], dp[10001];
int main(){
    int t;
    while(scanf("%d%d%d",&arr[0],&arr[1],&t)!=-1){
        memset(dp,-1,sizeof dp);
        dp[0]=0;
        for(int i : arr)
            for(int j=i;j<=t;j++)
                if(dp[j-i]!=-1)
                    dp[j]=max(dp[j-i]+1, dp[j]);
        if(dp[t]!=-1)printf("%d\n",dp[t]);
        else {
            for(int i=t-1;i>=0;i--)
                if(dp[i]!=-1){
                    printf("%d %d\n",dp[i], t-i);
                    break;
                }
        }
    }
    return 0;
}