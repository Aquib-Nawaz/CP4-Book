#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

unordered_map<int,int>mp;
int cnt;
vector<int>adjL[30];
int dp[30][30];

int getAndReturn(int u=-1){
    if(u==-1)
        scanf("%d",&u);
    if(mp.count(u)==0)
        mp[u]=cnt++;
    return mp[u];
}

void bfs(int s){
    if(dp[s][s]==0)return;
    dp[s][s]=0;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v:adjL[u]){
            if(dp[s][v]>dp[s][u]+1){
                dp[s][v]=dp[s][u]+1;
                q.push(v);
            }
        }
    }
}

int main(){
    int N,u,v,w,C=0;
    while(scanf("%d",&N), N){
        mp.clear();
        cnt=0;
        for(int i=0;i<N;i++){
            u = getAndReturn();
            v = getAndReturn();
            adjL[u].push_back(v);
            adjL[v].push_back(u);
        }
        for(int i=0;i<cnt;i++)
            for(int j=0;j<cnt;j++)
                dp[i][j]=1e9+1;

        while(scanf("%d%d", &v,&w), v||w){
            u= getAndReturn(v);
            bfs(u);
            int ans=0;
            for(int i=0;i<cnt;i++){
                if(dp[u][i]>w)ans++;
            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", ++C,ans,v,w);
        }
        for(int i=0;i<cnt;i++)
            adjL[i].clear();
    }
}