#include <iostream>
using namespace std;
typedef long long ll;

#define INF (-1e18)

int g[75][75],x,n,k, dir[2]={-1,1};
ll dp[2][75][6];

void process(int i, int j, int l){
    for(int d:dir){
        int nneg=l;
        ll sum=0;
        for(int j1=j;j1>=0&&j1<n;j1+=d){
            if(g[i][j1]<0)nneg--;
            sum+=g[i][j1];
            if(nneg<0)break;
            dp[x^1][j1][nneg]=max(dp[x][j][l]+sum, dp[x^1][j1][nneg]);
        }
    }
}

int main(){
    int C=0;
    while (scanf("%d%d", &n,&k),n){
        for(int i=0;i<n;i++)for(int j=0;j<=k;j++)dp[0][i][j]=INF;
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&g[i][j]);
        dp[0][0][k]=0;
        for(int i=0;i<n;i++){
            x=i&1;
            for(int j=0;j<n;j++)for(int l=0;l<=k;l++)dp[x^1][j][l]=INF;
            for(int j=0;j<n;j++)for(int l=0;l<=k;l++)
                if(dp[x][j][l]!=INF)process(i,j,l);
        }
        ll ans=INF;
        for(int i=0;i<=k;i++)ans = max(ans,dp[x^1][n-1][i]);
        printf("Case %d: ",++C);
        if(ans==INF)printf("impossible\n");
        else printf("%lld\n",ans);
    }
}