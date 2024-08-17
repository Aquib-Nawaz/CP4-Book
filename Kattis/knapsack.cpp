#include <iostream>
#include <cstring>
using namespace std;

int dp[2001][2001], arr[2001];

int cnt;
void print(int C, int n){
    int res = C;
    for(int i=n;i>0;i--){
        if(dp[res][i] == dp[res][i-1]) continue;
//        printf("%d\n",i);
        res-=arr[i];
        cnt++;
    }
    printf("%d\n",cnt);
    res = C;
    bool f=true;
    for(int i=n;i>0;i--){
        if(dp[res][i] == dp[res][i-1]) continue;
        if(!f)printf(" ");
        f=false;
        printf("%d",i-1);
        res-=arr[i];
    }
    printf("\n");
}

int main(){
    int C,n,d,v;
    while(scanf("%d%d",&C,&n)!=-1){
        memset(dp[0],0,sizeof dp[0]);

        for(int i=1;i<=n; i++){
            scanf("%d%d",&v,&d);
            arr[i]=d;
            for(int w=0;w<=C;w++){
                dp[w][i]=dp[w][i-1];
                if(w-d>=0)
                    dp[w][i]=max(dp[w][i],dp[w-d][i-1]+v);
            }
        }

        cnt=0;
        print(C,n);
    }
}