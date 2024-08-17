#include <iostream>
using namespace std;
typedef long long ll;
ll dp[10000];
struct mypair{
    int h,w;
}arr[10000];
int main(){
    int n,T,C=0,h,w;
    ll incr,decr;
    scanf("%d",&T);
    while (T--) {
        scanf("%d",&n);
        incr=decr=0;
        for(int i=0;i<n;i++)scanf("%d",&arr[i].h);
        for(int i=0;i<n;i++)scanf("%d",&arr[i].w);
        for(int i=0;i<n;i++){
            w = arr[i].w;
            h = arr[i].h;
            ll &t= dp[i];
            t=w;
            for(int j=0;j<i;j++)
                if(arr[j].h<h)
                    t=max(dp[j]+w,t);
            incr = max(t,incr);
        }
        for(int i=n-1;i>=0;i--){
            w = arr[i].w;
            h = arr[i].h;
            ll &t= dp[i];
            t=w;
            for(int j=i+1;j<n;j++)
                if(arr[j].h<h)
                    t=max(dp[j]+w,t);
            decr = max(t,decr);
        }

        printf("Case %d. ", ++C);
        if(incr>=decr)
            printf("Increasing (%lld). Decreasing (%lld).\n",incr,decr);
        else
            printf("Decreasing (%lld). Increasing (%lld).\n",decr,incr);
    }
}