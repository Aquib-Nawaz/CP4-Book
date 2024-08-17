#include <iostream>
#include <bitset>
#include <cstring>
using namespace std;
bitset<200>check;
int cur[9], h, curmax[9];
int dp[9][9][9], dp1[9][9];

void dfs(int curh, int curk, int last, int sum){
    check.set(sum);
    if(curh==h)return ;
    for(int i=last;i<=curk;i++)
        dfs(curh+1,curk,i,sum+cur[i]);
}

void solve(int curk){

    for(int i=cur[curk-1]+1;i<=curmax[curk-1]+1;i++){
        check.reset();
        cur[curk]=i;
        dfs(0,curk,1,0);
        int num=0;
        while(check[++num]);
        curmax[curk]=num-1;
        if(curmax[curk]>dp1[h][curk]){
            dp1[h][curk]=num-1;
            memcpy(dp[h][curk], cur, sizeof(cur));
        }
        if(curk!=9-h)
            solve(curk+1);
    }
}

int main(){
    for(int i=0;i<9;i++)dp1[0][i] = dp1[i][0]=0;
    cur[0]=curmax[0]=0;
    for(h=1;h<9;h++)solve(1);
    int k;
    while(scanf("%d %d",&h,&k),h!=0 && k!=0){
        for(int i=1;i<=k;i++)
            printf("%3d",dp[h][k][i]);
        printf(" ->%3d\n", dp1[h][k]);
    }
}