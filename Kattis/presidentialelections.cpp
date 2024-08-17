#include <iostream>
using namespace std;

struct state{
    int v,w;
}arr[2016];

int dp[2018];

int main(){
    int n,d,c,f,u,s=0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        scanf("%d%d%d%d",&d,&c,&f,&u);
        arr[i].w = max((c+f+u)/2+1-c,0);
        if(arr[i].w>u)arr[i].v=0;
        else arr[i].v = d;
        s+=d;
    }
    int req = s/2+1;
    for(int i=0;i<=s+1;i++)dp[i]=1e9+1;
    dp[0]=0;
    for(int i=0;i<n;i++){
        for(int j=s-arr[i].v;j>=0;j--){
            dp[j+arr[i].v] = min(dp[j+arr[i].v],dp[j]+arr[i].w);
        }
    }
    int ans=1e9+1;
    for(int i=req;i<=s;i++){
        ans = min(ans,dp[i]);
    }
    if(ans>1e9)
        printf("impossible");
    else
        printf("%d",ans);
}