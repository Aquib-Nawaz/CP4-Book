#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

ll dp[66][66];

ll solve(int n, int k) {
    if(k>n)
        return 0;
    if(k==n)return 1;
    ll &ans=dp[n][k];
    if(ans!=-1) return ans;
    ans=0;
    if(k>0)
        ans+=solve(n-1,k-1);
    else
        ans+=1;
    for(int i=2;n-i>=k;i++)ans+=solve(n-i,k);
    return ans;
}
int main(){
    int n,k;
    memset(dp,-1,sizeof dp);
    while(scanf("%d%d",&n,&k),n>=0&&k>=0){
        printf("%lld\n",solve(n,k));
    }
}