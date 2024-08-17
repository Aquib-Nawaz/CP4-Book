#include <iostream>
#include <algorithm>
using namespace std;

int dp[100][100], ans[5000];

int main(){
    int T,C=0;
    scanf("%d",&T);
    dp[0][0]=0;
    while(T--) {
        int N, M;
        scanf("%d", &N);
        M = 0;
        for (int i = 1; i < N; i++) {
            int w;
            for (int j = 0; j < i; j++) {
                scanf("%d", &w);
                dp[i][j] = w;
                dp[j][i] = w;
            }
            dp[i][i] = 0;
        }
        bool impossible = false;
        for (int k = 0; k < N && !impossible; k++)
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    if (dp[i][j] > dp[i][k] + dp[k][j]) {
                        impossible = true;
                        break;
                    }
        printf("Case #%d:\n", ++C);
        if (impossible)printf("Need better measurements.\n\n");
        else {
            int cnt=0;
            for(int i=0;i<N;i++){
                for(int j=i+1;j<N;j++){
                    bool needed= true;
                    for(int k=0;k<N;k++){
                        if(k!=i && k!=j && dp[i][k]+dp[k][j]==dp[i][j]){
                            needed=false;
                            break;
                        }
                    }
                    if(needed)ans[cnt++]=i*N+j;
                }
            }
            printf("%d\n",cnt);
            for(int i=0;i<cnt;i++){
                int u=ans[i]/N;
                int v=ans[i]%N;
                printf("%d %d %d\n",u+1,v+1,dp[u][v]);
            }
            printf("\n");
        }
    }

}