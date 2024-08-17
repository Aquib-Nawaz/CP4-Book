#include <iostream>
#include <cstring>
using namespace std;
int arr[51];
int dp[51][51];

int solve(int l, int r){
    if(r-l<=1)return 0;
    if(dp[l][r]!=-1)return dp[l][r];
    int ret=1e9;
    for(int i=l+1;i<r;i++){
        ret=min(ret, solve(l,i)+solve(i,r));
    }
    return dp[l][r]=ret+arr[r]-arr[l];
}

int main(){
    int l,n;
    arr[0]=0;
    while(scanf("%d",&l),l){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",arr+i);
        arr[n+1]=l;
        n+=2;
        memset(dp,-1,sizeof dp);
        printf("The minimum cutting is %d.\n",solve(0,n-1));
    }
}