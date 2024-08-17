#include <iostream>
#include <cstring>
using namespace std;
int dp[27][10000];
int main(){
    int L,S,ans,C=0;
    memset(dp,0,sizeof dp);
    dp[0][0]=1;
    for(int i=1;i<=26;i++){
        for(int j=9999-i;j>=0;j--)
            for(int l=26;l>0;l--)
                dp[l][j+i]+=dp[l-1][j];
    }
    while(scanf("%d %d",&L,&S),L){
        ans=L>26?0:dp[L][S];
        printf("Case %d: %d\n",++C, ans);
    }

}