#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

typedef long long ll;

ll dp[1001][1001];
int n,m;
ll dfs(int u, int v){
    if(u>n || v>m)return 0;
    if(dp[u][v]!=-1)return dp[u][v];
    ll ans=dfs(u+1,v)+dfs(u,v+1);
    return dp[u][v]=ans;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d%d ", &n,&m);

        for(int i=0;i<n;i++){
            string s;
            getline(cin,s);
            stringstream ss(s);
            int u,v;
            ss >> u;
            for(int j=1;j<=m;j++)dp[u][j]=-1;
            while(ss>>v)dp[u][v]=0;
        }

        if(dp[n][m]==0)printf("0\n");
        else {
            dp[n][m]=1;
            printf("%lld\n", dfs(1,1));
        }
        if(T)printf("\n");
    }
}