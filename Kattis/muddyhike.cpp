#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int g[1000][1000], dp[1000][1000],N,M, dir[][2] = {{-1,0}, {1,0}, {0,1},
                                                   {0,-1}};
bool vis[1000][1000];
bool valid(int i, int j){
    if(i<0 || j<0 || i>=N || j>=M || vis[i][j])return false;
    return true;
}


int main(){
    scanf("%d%d", &N,&M);
    for(int i=0;i<N;i++)for(int j=0;j<M;j++)scanf("%d",g[i]+j), dp[i][j]=1e9, vis[i][j]= false;
    priority_queue<pair<int,int>>pq;
    for(int i=0;i<N;i++)pq.emplace(-g[i][0],i*M), dp[i][0]=g[i][0];
    int ans;
    while(!pq.empty()) {
        int i = pq.top().second / M, j = pq.top().second % M;
        pq.pop();
        if(vis[i][j])continue;
        vis[i][j] = true;
        if (j == M - 1){ans = dp[i][j]; break;}
        for (auto &k: dir) {
            int ii = i + k[0], jj = j + k[1];
            if (valid(ii, jj) && dp[ii][jj] > max(dp[i][j], g[ii][jj])) {
                dp[ii][jj] = max(dp[i][j], g[ii][jj]);
                pq.emplace(-dp[ii][jj], ii * M + jj);
            }
        }
    }
    printf("%d\n", ans);
}