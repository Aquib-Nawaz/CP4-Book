#include <iostream>
#include <cstring>
using namespace std;

int dp[11][20], arr[200];

int main(){
    int n,q,m,D,C=0;
    while(scanf("%d%d",&n,&q),n||q) {
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
        printf("SET %d:\n",++C);
        for (int _ = 1; _ <= q; _++) {
            scanf("%d%d", &D, &m);
            memset(dp, 0, sizeof dp);
            dp[0][0] = 1;
            for (int i = 0; i < n;i++){
                for(int j=m;j>0;j--){
                    for(int k=0;k<D;k++){
                        int next = (arr[i]%D+D+k)%D;
                        dp[j][next] += dp[j-1][k];
                    }
                }
            }
            printf("QUERY %d: %d\n", _, dp[m][0]);
        }
    }
}