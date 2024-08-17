#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int g[1000][1000], dp[1000][1000],N,M, dir[][2] = {{-1,0}, {1,0}, {0,1},
                                                   {0,-1}};

bool valid(int i, int j){
    if(i<0 || j<0 || i>=N || j>=M)return false;
    return true;
}


int main(){
    scanf("%d%d", &N,&M);
    for(int i=0;i<N;i++)for(int j=0;j<M;j++)scanf("%d",g[i]+j), dp[i][j]=1e9;
    priority_queue<pair<int,int>>pq;
    pq.emplace(0,0);
    dp[0][0]=0;
    while(!pq.empty()) {
        int w=pq.top().first,i = pq.top().second / M, j = pq.top().second % M;
        pq.pop();
        if (i == N - 1 && j == M - 1)break;
        if (dp[i][j] != -w)continue;
        for (auto &k: dir) {
            int ii = i + k[0], jj = j + k[1];
            if (valid(ii, jj) && dp[ii][jj] > max(dp[i][j], g[ii][jj] - g[i][j])) {
                dp[ii][jj] = max(dp[i][j], g[ii][jj] - g[i][j]);
                pq.emplace(-dp[ii][jj], ii * M + jj);
            }
        }
    }
    printf("%d", dp[N - 1][M - 1]);
}