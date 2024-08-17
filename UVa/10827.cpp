#include <iostream>
using namespace std;

int arr[75][75],n;
int getV(int i, int lj, int rj, bool f){
    int t = arr[i%n][rj];
    if(lj>0)t-=arr[i%n][lj-1];
    return f?t:arr[i%n][n-1]-t;
}
int main(){
    int T, val,ans,x,t,ts,mx;
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)scanf("%d",&arr[i][j]), arr[i][j]+=j==0?0:arr[i][j-1];
        ans=arr[0][0];
        for(int lj=0;lj<n;lj++)for(int rj=lj;rj<n;rj++){
            for(int k=0;k<2;k++){
                if(k==0 && (lj==0||rj==n-1))continue;
                x=val=ts=mx=0;
                for(int i=0;i<n ; i++){
                    t = getV(i,lj,rj,k);
                    val+= t;
                    ts+=t;
                    x+=t;
                    ans = max(val,ans);
                    mx = min(x,mx);
                    if(val<0)val=0;
                    if(x>0)x=0;
                }
                if(ts!=mx)
                    ans = max(ts-mx,ans);
            }
        }

        printf("%d\n",ans);

    }
}