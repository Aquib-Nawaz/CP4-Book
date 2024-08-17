#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
ll dp[86];

ll f(int n){
    if(n<=2)return 1;
    if(dp[n]!=-1)return dp[n];
    return dp[n]=f(n-1)+f(n-2);
}
int main(){
    memset(dp,-1,sizeof dp);
    int n;
    while(scanf("%d",&n),n){
        printf("%lld\n",f(n));
    }
}