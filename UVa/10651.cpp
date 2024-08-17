#include <iostream>
#include <cstring>
using namespace std;

int dp[1<<12];

int solve(int st){
    int & ret= dp[st];
    if(ret!=-1)return ret;
    ret = __builtin_popcount(st);
    for(int i=1;i<11;i++){
        if(!(st&(1<<i)))continue;
        if(st&(1<<i-1)&&!(st&(1<<i+1)))
            ret = min(ret, solve(st^(7<<(i-1))));
        if(st&(1<<i+1)&&!(st&(1<<i-1)))
            ret = min(ret, solve(st^(7<<(i-1))));
    }
    return ret;
}
char line[13];
int main(){
    int T, st;
    scanf("%d",&T);
    memset(dp,-1,sizeof dp);
    while(T--){
        st=0;
        scanf("%s", line);
        for(int i=0;i<12;i++)
            if(line[i]=='o')st|=(1<<i);
        printf("%d\n", solve(st));
    }
}