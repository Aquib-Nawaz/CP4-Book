#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct mypair{
    int x,y;
}arr[11];

int dist(int i, int j){
    return abs(arr[i].x - arr[j].x) + abs(arr[i].y - arr[j].y);
}
#define LSOne(x) (x&(-x))
int dp[11][1<<10],N;

int solve(int pos, int mask){
    if(mask == 0) return dist(pos, 0);
    int &ans = dp[pos][mask];
    if(ans != -1) return ans;
    ans=1e9;
    int m = mask, two_pow_v,v;
    while (m) {
        two_pow_v = LSOne(m);
        v = __builtin_ctz(two_pow_v)+1;
        ans = min(ans, dist(pos,v) + solve(v, mask^two_pow_v)); // keep the min
        m ^= two_pow_v;
    }
    return ans;
}

int main() {
    int T;
    scanf("%d",&T);
    while (T--){
        scanf("%*d%*d%d%d", &arr[0].x, &arr[0].y);
        scanf("%d",&N);
        for(int i=1;i<=N;i++){
            scanf("%d %d",&arr[i].x, &arr[i].y);
        }
        memset(dp,-1,sizeof dp);
        printf("%d\n", solve(0,(1<<N)-1));
    }
    return 0;
}