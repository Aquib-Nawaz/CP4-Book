#include <iostream>
using namespace std;

int dp[10001][100], w,h;

int dfs(int l, int i){
    if(l==0||i==w)return 1;
    if(dp[l][i]!=-1)return dp[l][i];
    int ret=0;
    for(int j=0;j<=min(h,l);j++)ret = (ret+dfs(l-j,i+1))%1000000007;
    return dp[l][i]=ret;
}

int main(){
    int l;
    scanf("%d%d%d",&l,&w,&h);
    for(int i=0;i<=l;i++)for(int j=0;j<w;j++)dp[i][j]=-1;
    int ans=dfs(l,0)-min(h,l/w)-1;

    printf("%d\n", ans);
}