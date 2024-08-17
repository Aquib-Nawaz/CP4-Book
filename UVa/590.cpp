#include <iostream>
#include <vector>
#include <cstring>
using namespace std;


vector<int> adjL[10][10];
int dp[1000][10];
int n,l;
int dfs(int u, int v){

    if(u==l)
        return v==n-1?0:1e9;

    if(dp[u][v]!=-1)return dp[u][v];
    int mn=1e9,w;
    for(int i=0;i<n;i++){
        if(i==v)continue;
        w = adjL[v][i][u%adjL[v][i].size()];
        if(w!=0)mn=min(w+dfs(u+1,i), mn);
    }
    return dp[u][v]=mn;
}

int main(){
    int C=0;
    while (scanf("%d%d", &n,&l)==2 && n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                int d;
                scanf("%d", &d);
                adjL[i][j].resize(d);
                for(int k=0;k<d;k++){
                    scanf("%d", &adjL[i][j][k]);
                }
            }
        }
        memset(dp,-1,sizeof dp);
        printf("Scenario #%d\n", ++C);
        int ans = dfs(0,0);
        if(ans==1e9)printf("No flight possible.\n");
        else printf("The best flight costs %d.\n", ans);
        printf("\n");
    }
}