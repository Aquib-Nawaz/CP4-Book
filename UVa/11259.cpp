#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

ll dp[100001];

int arr[4], d[4];

int main(){
    int T,n=4,q,v,_v,t;
    scanf("%d",&T);
    while(T--){
        for(int i=0;i<n;i++)scanf("%d",arr+i);
        scanf("%d",&q);
        memset(dp,0,sizeof dp);
        dp[0]=1;
        for(int i=0;i<n;i++)
            for(int j=arr[i];j<=100000;j++) dp[j]+=dp[j-arr[i]];
        while(q--){
            for(int i=0;i<n;i++)scanf("%d",&t), d[i] = arr[i]*(t+1);
            scanf("%d",&v);

            ll ans = dp[v];
            for(int i=0;i<n;i++){
                _v = v-d[i];
                if(_v>=0) ans-=dp[_v];
            }
            for(int i=0;i<n;i++)for(int j=i+1;j<n;j++){
                _v =  v-d[i]-d[j];
                if(_v>=0) ans+=dp[_v];
            }
            for(int i=0;i<n;i++){
                _v = v;
                for(int j=0;j<n;j++)if(j!=i)_v-=d[j];
                if(_v>=0) ans-=dp[_v];
            }
            _v=v;
            for(int i=0;i<n;i++)_v-=d[i];
            if(_v>=0) ans+=dp[_v];
            printf("%lld\n",ans);
        }
    }

}