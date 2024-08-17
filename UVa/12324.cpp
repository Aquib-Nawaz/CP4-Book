#include <iostream>
#include <cstring>
using namespace std;

int dp[100][101],N;
struct mypair{
    int t,b;
} arr[100];
int solve(int n, int k){
    if(n==N) return 0;
    if(k>N-n)k=N-n;
    int &ret = dp[n][k];
    if(ret!=-1)return ret;
    ret = solve(n+1,k+arr[n].b)+arr[n].t;
    if(k>0) ret = min(ret,solve(n+1,k+arr[n].b-1)+arr[n].t/2);
    return ret;
}

int main(){
    while(scanf("%d",&N),N){
        for(int i=0;i<N;i++)scanf("%d%d",&arr[i].t,&arr[i].b);
        memset(dp,-1,sizeof dp);
        printf("%d\n",solve(0,0));
    }
}