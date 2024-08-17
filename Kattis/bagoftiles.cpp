#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

int arr[30],dp[31][10001], comb[31][31];


void _comb() {
    for(int i=0;i<=30;i++)comb[i][0] = comb[i][i] = 1;
    for(int i=1;i<=30;i++)for(int j=1;j<i;j++)comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
}

int main() {
    int T,C=0,t,n,m;
    memset(comb,0,sizeof comb);
    _comb();
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d", &arr[i]);
        scanf("%d%d",&m,&t);
        memset(dp,0,sizeof dp);
        dp[0][0] = 1;
        for(int i=0;i<n;i++) {
            for(int j=m;j>0;j--) {
                for(int k=arr[i];k<=t;k++) {
                    dp[j][k] += dp[j-1][k-arr[i]];
                }
            }
        }
        printf("Game %d -- %d : %d\n",++C, dp[m][t], comb[n][m]-dp[m][t]);
    }
}