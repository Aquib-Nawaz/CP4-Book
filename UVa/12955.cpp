#include <iostream>
using namespace std;
int arr[10], dp[100001];

int main(){
    arr[0]=1;
    for(int i=1;i<10;i++)arr[i] = arr[i-1]*(i+1);
    memset(dp,-1,sizeof dp);
    dp[0]=0;
    for(int i=0;i<10;i++){
        for(int j=arr[i];j<=100000; j++){
            if(dp[j-arr[i]!=-1]){
                if(dp[j]==-1)dp[j]=dp[j-arr[i]]+1;
                else dp[j]=min(dp[j],dp[j-arr[i]]+1);
            }
        }
    }
    int N;
    while(scanf("%d",&N)!=-1){
        printf("%d\n",dp[N]);
    }
}