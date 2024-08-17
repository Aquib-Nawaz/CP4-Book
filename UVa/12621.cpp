#include <iostream>
using namespace std;

bool dp[25001];

int main(){
    int T, w,n,d,cmax;
    scanf("%d",&T);
    while (T--){
        scanf("%d%d", &w,&n);
        w/=10;
        memset(dp,0,sizeof dp);
        cmax = n*250+1;
        dp[0]=true;
        for(int i=0;i<n;i++){
            scanf("%d",&d);
            d/=10;
            for(int j=cmax-d;j>=0;j--){
                if(!dp[j])continue;
                dp[j+d]=true;
                if(j+d>=w)cmax = j+d;
            }
        }
        if(cmax==n*250+1)printf("NO SOLUTION\n");
        else printf("%d\n",cmax*10);
    }
}