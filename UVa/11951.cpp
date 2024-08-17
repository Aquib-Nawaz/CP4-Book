#include <iostream>
using namespace std;

typedef long long ll;

int arr[100][100];

int main(){
    int T,n,m,k,C=0, ret;
    ll cost,retp;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<n;i++)for(int j=0;j<m;j++)scanf("%d",arr[i]+j), arr[i][j]+=j==0?0:arr[i][j-1];
        retp=ret=0;
        for(int lj=0;lj<m;lj++)for(int rj=lj;rj<m;rj++){
            cost=0;
            for(int li=0,ri=0;ri<n;ri++){
                cost+=arr[ri][rj];
                if(lj>0)cost-=arr[ri][lj-1];

                while(cost>k){
                    cost-=arr[li][rj];
                    if(lj>0)cost+=arr[li][lj-1];
                    li++;
                }
                if((ri-li+1)*(rj-lj+1)>ret || (ri-li+1)*(rj-lj+1)==ret && retp>cost)
                    ret=(ri-li+1)*(rj-lj+1), retp=cost;
            }
        }
        printf("Case #%d: %d %d\n",++C, ret, (int)retp);
    }
}