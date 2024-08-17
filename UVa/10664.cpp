#include <iostream>
using namespace std;
int arr[20];
bool dp[101];
int main(){
    int T,n,ret,d,t;
    scanf("%d ",&T);
    while(T--){
        char c;
        t=n=0;
        do{
            ret=scanf("%d%c",&d,&c);
            t+=d;
            arr[n++]=d;
        }while(c!='\n'&&ret==2);
        if(t&1){
            printf("NO\n");
            continue;
        }
        t/=2;
        for(int i=1;i<=t;i++)dp[i]= false;
        dp[0]=true;
        for(int i=0;i<n;i++){
            d=arr[i];
            for(int j=t-d;j>=0;j--){
                if(!dp[j]||dp[j+d])continue;
                dp[j+d]=true;
            }
        }
        if(dp[t])printf("YES\n");
        else printf("NO\n");
    }

}