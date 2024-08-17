#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int dp[3601], arr[16];

bool inRange(int v){
    return v>=0 && dp[v]==-1;
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int N, t,u,v,d;
        scanf("%d%d",&N, &t);
        for(int i=0;i<N;i++)scanf("%d", arr+i);
        memset(dp,-1,sizeof dp);
        queue<int>q;
        q.push(0);
        dp[0]=0;
        while (!q.empty()){
            u=q.front();
            q.pop();
            if(u==t)break;
            d = dp[u];
            for(int i=0;i<N;i++){
                v=min(3600,u+arr[i]);
                if(inRange(v)){
                    dp[v]=d+1;
                    q.push(v);
                }
            }
        }
        v=t;
        while(dp[t]==-1)t++;
        printf("%d %d\n",dp[t], t-v);
    }
}