#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
ll dp[1001][1001];

int arr[1000],N;

ll solve(int n,int k){
    if(n+k+1==N-1)return arr[N-1];
    ll &ans=dp[n][k];
    if(ans!=-1)return ans;

    if(n+k+1<N)
        ans = solve(n+k+1, k+1)+arr[n+k+1];
    if(n-k>=0&&n>0)
        if(ans==-1 || solve(n-k, k) !=-1 && ans > solve(n-k, k)+arr[n-k])
            ans = solve(n-k, k)+arr[n-k];

    return ans;
}

int main(){
    memset(dp,-1,sizeof dp);

    scanf("%d",&N);
    for(int i=0;i<N;i++)scanf("%d",arr+i);
    printf("%lld\n",solve(0,0));
}