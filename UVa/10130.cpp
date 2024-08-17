#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int dp[1000][31], n;

struct mypair{
    int p,w;
    bool const operator < (const mypair& rhs) const {
        return w<rhs.w;
    }
}arr[1001];

int solve(int idx, int w){
    if(idx>=n || w<arr[idx].w)return 0;
    if(dp[idx][w]!=-1)return dp[idx][w];
    return dp[idx][w] = max(solve(idx+1,w),solve(idx+1,w-arr[idx].w)+arr[idx].p);
}


int main(){
    int T,m,ans,d;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d %d",&arr[i].p,&arr[i].w);
        }
        sort(arr,arr+n);
        memset(dp,-1,31*n*sizeof(int));
        scanf("%d",&m);
        ans=0;
        for(int i=0;i<m;i++)scanf("%d",&d), ans+=solve(0,d);
        printf("%d\n",ans);
    }
}