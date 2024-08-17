#include <iostream>
#include <cstring>
using namespace std;

struct mypair{
    int w,c;

}arr[1000];

int dp[1000][3001],N;

int solve(int id, int mw){
    if(id==N || 0==mw) return 0;
    if(dp[id][mw]!=-1) return dp[id][mw];
    return dp[id][mw] = max(solve(id+1, mw), mw>=arr[id].w?1+solve(id+1, min(mw-arr[id].w, arr[id].c)):0);
}

int main(){
    while (scanf("%d",&N),N){
        for(int i=0;i<N;i++) scanf("%d%d",&arr[i].w,&arr[i].c), memset(dp[i], -1, sizeof dp[i]);
        int ans=0;
        for(int i=0;i<N;i++){
            ans = max(ans, solve(i+1, arr[i].c));
        }
        printf("%d\n",1+ans);
    }
}