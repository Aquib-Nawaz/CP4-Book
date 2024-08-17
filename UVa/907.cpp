#include <iostream>
using namespace std;
typedef long long ll;

int v[601],x;
ll pref[602], dp[2][601];

ll cost(int i, int j){
    return pref[j+1]-pref[i];
}

void compute(int l, int r, int optl, int optr){
    if (l > r)
        return;
    int mid = (l + r) >> 1;
    pair<ll,int> best = {1e18,-1};
    for (int i = optl; i <= min(mid, optr); i++){
        best = min(best, {max(cost(i, mid) , i?dp[x][i-1]:0), i});
    }
    dp[x^1][mid] = best.first;
    compute(l, mid - 1, optl, best.second);
    compute(mid + 1, r, best.second, optr);
}

int main(){
    int n,k;
    while (scanf("%d%d", &n,&k)!=-1){
        n++;
        pref[0]=0;
        for(int i=0;i<n;i++)scanf("%d", v+i), dp[0][i] = pref[i+1]=pref[i]+v[i];
        x=1;
        for(int i=0;i<k;i++){
            x=i&1;
            compute(0,n-1,0,n-1);
        }
        printf("%lld\n" ,dp[x^1][n-1]);
    }
}