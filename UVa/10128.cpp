#include <iostream>
using namespace std;

long long dp[14][14][14];

void solve(){
    for(int i=0;i<14;i++)for(int j=0;j<14;j++)dp[1][i][j]=0;
    dp[1][1][1]=1;
    for(int N=2;N<14;N++){
        for(int P=1;P<=N;P++){
            for(int R=1;R<=N-P+1;R++){
                dp[N][P][R]=dp[N-1][P-1][R]+dp[N-1][P][R-1]+dp[N-1][P][R]*(N-2);
            }
        }
    }
}


int main(){
    int n,N,P,R;
    solve();
    scanf("%d", &n);
    while(n--){
        scanf("%d %d %d", &N,&P, &R);
        if(P>N||R>N) printf("0\n");
        else printf("%lld\n", dp[N][P][R]);
    }
}