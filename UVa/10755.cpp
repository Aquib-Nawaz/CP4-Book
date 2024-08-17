#include <iostream>
using namespace std;

typedef long long ll;

ll arr[20][20][20];

int main(){
    int T,A,B,C,d;
    scanf("%d",&T);
    bool f=true;
    while(T--){
        scanf("%d%d%d",&A,&B,&C);
        for(int i=0;i<A;i++)
            for (int j = 0; j < B; j++)
                for (int k = 0; k < C; k++) {
                    scanf("%lld", &arr[i][j][k]);
                    if(j>0)
                        arr[i][j][k] += arr[i][j-1][k];
                    if(k>0)
                        arr[i][j][k] += arr[i][j][k-1];
                    if(j>0&&k>0)
                        arr[i][j][k] -= arr[i][j-1][k-1];
                }
        ll ans = arr[0][0][0],val;
        for(int lj=0;lj<B;lj++)for(int rj=lj;rj<B;rj++)for(int lk=0;lk<C;lk++)
            for(int rk=lk;rk<C; rk++){
                val=0;
                for(int i=0;i<A;i++){
                    val+=arr[i][rj][rk];
                    if(lj>0) val -= arr[i][lj-1][rk];
                    if(lk>0) val -= arr[i][rj][lk-1];
                    if(lj>0 && lk>0) val += arr[i][lj-1][lk-1];
                    ans = max(ans,val);
                    if(val<0)val=0;
                }
            }
        if(!f){
            printf("\n");
        }
        f=false;
        printf("%lld\n",ans);
    }
}