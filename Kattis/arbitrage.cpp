#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

typedef long double ld;
char cur[4];
ld dp[500][500];
int main(){
    int N,M;
    while(scanf("%d", &N)==1){
        if(N==0)break;
        unordered_map<string, int> mp;
        for(int i=0;i<N;i++){
            scanf("%s", cur);
            mp[string(cur)] = i;
            for(int j=0;j<N;j++)dp[i][j]=0;
            dp[i][i]=1;
        }
        scanf("%d", &M);
        for(int i=0;i<M;i++){
            int u,v,a,b;
            scanf("%s", cur);
            u=mp[cur];
            scanf("%s %d:%d", cur, &a,&b);
            v=mp[cur];
            dp[u][v]=(ld)b/a;
        }
        for(int k=0;k<N;k++){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++){
                    dp[i][j]=max(dp[i][j],dp[i][k]*dp[k][j]);
                }
            }
        }
        bool ok=true;
        for(int i=0;i<N;i++){
            if(dp[i][i]>1+1e-20)ok= false;
        }
        if(ok)printf("ok\n");
        else printf("Arbitrage\n");
    }

}