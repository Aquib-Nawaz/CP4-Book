#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

char g[1000][1001];
int dp[1000][1000], N;
bool vis[1000][1000];
#define MODULO std::numeric_limits<int>::max()
typedef long long ll;

int dfs(int x, int y){
    if(x<0||x>=N||y<0||y>=N||g[x][y]=='#')return 0;
    if(dp[x][y]!=-1)return dp[x][y];
    return dp[x][y]=((ll)dfs(x+1,y)+dfs(x,y+1))%MODULO;
}

bool dfs1(int x, int y){
    if(x<0||x>=N||y<0||y>=N||g[x][y]=='#'||vis[x][y])return false;
    if(x==N-1&&y==N-1)return true;
    vis[x][y]=true;
    return dfs1(x+1,y)||dfs1(x,y+1)||dfs1(x-1,y)||dfs1(x,y-1);
}

int main() {
    scanf("%d" ,&N);
    for(int i=0;i<N;i++)scanf("%s", g[i]);
    memset(dp,-1,sizeof dp);
    dp[N-1][N-1]=1;
    int ans=dfs(0,0);
    if(ans!=0)printf("%d\n", ans);
    else {
        memset(vis,0,sizeof vis);
        if(dfs1(0,0))printf("THE GAME IS A LIE\n");
        else printf("INCONCEIVABLE\n");
    }
}