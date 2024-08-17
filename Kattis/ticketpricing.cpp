#include <iostream>
#include <cstring>
using namespace std;
int dp[54][301],len[54],W;
struct {
    int p,n;
}arr[54][101];

int solve(int w, int n){
    if(n==0 || w==W+1)return 0;
    int &ans = dp[w][n];
    if(ans!=-1)return ans;
    ans=0;
    for(int i=0;i<len[w];i++){
        ans = max(ans, solve(w+1,max(0,n-arr[w][i].n)) + arr[w][i].p*min(n,arr[w][i].n));
    }
    return ans;
}

int main(){
    int N,k;
    memset(dp,-1,sizeof dp);
    scanf("%d%d",&N,&W);
    for(int i=0;i<=W;i++){
        scanf("%d",&k);
        len[i]=k;
        for(int j=0;j<k;j++)
            scanf("%d",&arr[i][j].p);
        for(int j=0;j<k;j++)
            scanf("%d",&arr[i][j].n);
    }
    int ans=0, ansi;
    for(int i=0,cur;i<len[0];i++){
        cur = solve(1,max(0,N-arr[0][i].n)) + arr[0][i].p*min(N,arr[0][i].n);
        if( cur>ans)ans=cur,ansi=i;
    }
    printf("%d\n%d\n",ans,arr[0][ansi].p);
}