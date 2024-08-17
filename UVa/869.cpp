#include <iostream>
#include <cstring>
using namespace std;

bool dp[2][26][26];
void fw(int x){
    char u,v;
    int m;
    scanf("%d", &m);
    for(int i=0;i<m;i++){
        scanf(" %c %c", &u,&v);
        dp[x][u-'A'][v-'A']=dp[x][v-'A'][u-'A']=true;
    }
    int n=26;
    for(int i=0;i<n;i++)dp[x][i][i]= true;
    for(int j=0;j<n;j++)for(int i=0;i<n;i++)for(int k=0;k<n;k++)dp[x][i][k]|=dp[x][i][j]&dp[x][j][k];
}

int main(){
    int T,n=26;
    scanf("%d", &T);
    while(T--){
        memset(dp,0,sizeof dp);
        fw(0);
        fw(1);
        bool equi=true;
        for(int i=0;i<n;i++)for(int j=i+1;j<n;j++)if(dp[0][i][j]!=dp[1][i][j])equi=false;
        printf("%s\n", equi?"YES":"NO");
        if(T)printf("\n");
    }
}