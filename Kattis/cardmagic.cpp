#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

int dp[101][5001],N,K,S;

int dfs(int n, int s){
    if(n<0)return s==S;
    if(s>=S)return 0;
    if(dp[n][s]!=-1)return dp[n][s];
    ll ret=0;
    for(int i=1;i<=K;i++){
        ret+=dfs(n-1,s+i);
    }
    return dp[n][s]=ret%1000000009;
}

int main(){
    scanf("%d%d%d", &N,&K,&S);
    memset(dp,-1,sizeof dp);
    printf("%d\n", dfs(N-1,0));
}