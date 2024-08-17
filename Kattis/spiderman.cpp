#include <iostream>
#include <cstring>
using namespace std;

int arr[40], dp[40][1001],  N;
bool par[40][1001];
int solve(int i, int k){
    if(k<0)return 1e9;
    if(i==N) return k==0?0:1e9;
    int &ans = dp[i][k];
    if(ans!=-1)return ans;
    ans=max(k,solve(i+1, arr[i]+k));
    par[i][k]=true;
    if(max(k,solve(i+1, k-arr[i]))<ans)ans=max(k,solve(i+1, k-arr[i])), par[i][k]=false;
    return ans;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<N;i++)scanf("%d", arr+i);
        memset(dp,-1,sizeof dp);
        if(solve(0,0)>1000)printf("IMPOSSIBLE\n");
        else{
           for(int i=0,k=0;i<N;i++){
               printf("%c",par[i][k]?'U':'D');
               k+=par[i][k]?arr[i]:-arr[i];
           }
            printf("\n");
        }
    }
}