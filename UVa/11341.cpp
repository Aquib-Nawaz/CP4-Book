#include <iostream>
#include <algorithm>
#include <cstring>
using  namespace std;

int arr[10][100], dp[10][101], n, m ;

int solve(int id, int t) {
    if (id == n)return 0;
    if (dp[id][t] != -1) return dp[id][t];

    int pos = lower_bound(arr[id], arr[id] + m, 5) - arr[id];
    int &ans = dp[id][t];
    ans=-2;
    for(int tu = pos+1,v; tu<=t && (v=solve(id+1,t-tu))!=-2; tu++){
        ans = max(ans, arr[id][tu-1] + v);
    }
    return ans;
}

int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d", arr[i]+j);
        memset(dp, -1, sizeof dp);
        double ret = solve(0, m)*1.0/n;
        if(ret<0)printf("Peter, you shouldn't have played billiard that much.\n");
        else printf("Maximal possible average mark - %.2lf.\n", ret+1e-10);
    }
}