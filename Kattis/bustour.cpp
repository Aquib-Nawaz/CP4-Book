#include <iostream>
#include <cstring>
using namespace std;

int dp[2][20][1<<18], dist[20][20], n;
#define LSOne(x) ((x)&-(x))
int solve(int pos, int mask, int type){
    if(mask==0){
        if(type==0)return dist[pos][n-1];
        else return dist[pos][0];
    }
    int &ans = dp[type][pos][mask];
    if (ans != -1) return ans;
    ans = 2000000000;
    int m = mask,v,two_pow_v;
    while (m) {
        two_pow_v = LSOne(m);
        v = __builtin_ctz(two_pow_v)+1;
        ans = min(ans, dist[pos][v] + solve(v, mask^two_pow_v, type));
        m -= two_pow_v;
    }
    return ans;
}

int main(){
    int m, u,v,w,C=0;
    while(scanf("%d%d",&n,&m)!=-1){
        for(int i=0;i<2;i++)for(int j=0;j<n;j++)memset(dp[i][j], -1, (1<<(n-2))*sizeof (int));
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)dist[i][j]=1e9;
        for(int i=0;i<m;i++)scanf("%d%d%d",&u,&v,&w),dist[u][v]=dist[v][u]=w;

        for (int k = 0; k < n; k++)
            for (int i = 0; i <n; i++)
                for (int j = 0; j < n; j++)
                    if (dist[i][j] > (dist[i][k] + dist[k][j]))
                        dist[i][j] = dist[i][k] + dist[k][j];
        int ans=1e9,cur1,cur2;
        if(n==3)
            ans = solve(0,1,0)*2;

        else
            for(int i=0,mask,negmask, two_pow_v;i<1<<(n-2);i++){
                cur1=cur2=1e9;
                if(__builtin_popcount(i)!=(n-2)/2)continue;
                mask=i,negmask=i^((1<<(n-2))-1);
                while(mask){
                    two_pow_v = LSOne(mask);
                    v = __builtin_ctz(two_pow_v)+1;
                    mask-=two_pow_v;
                    cur1 = min(cur1,solve(v, negmask ,0)+solve(v,i^two_pow_v,1));
                    cur2 = min(cur2, solve(v, negmask, 1)+solve(v,i^two_pow_v,0));
                }
                ans = min(ans,cur1+cur2);
            }

        printf("Case %d: %d\n",++C,ans);
    }

}