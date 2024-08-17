#include <iostream>
using namespace std;

typedef long double ld;
ld dp[2][10];

int main(){
    int N,k,x;
    while(scanf("%d%d",&k,&N)!=-1){
        ld ans;
        if(N>1&&k>0){
            for(int i=0;i<10;i++)dp[1][i]=1.;
            for(int n=2;n<=N;n++){
                x=n&1;
                for(int i=1;i<k;i++)
                    dp[x][i]=(dp[1-x][i-1]+dp[1-x][i]+dp[1-x][i+1])/(k+1);

                dp[x][k] = (dp[1 - x][k - 1] + dp[1 - x][k]) / (k+1);
                dp[x][0] = (dp[1 - x][0] + dp[1 - x][1]) / (k+1);

            }
            ans=0;
            for(int i=0;i<=k;i++)ans+=dp[N&1][i];
            ans = ans*100/(k+1);
        }
        else ans=100;
        printf("%.5Lf\n",ans);
    }
}