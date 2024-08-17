#include <iostream>
using namespace std;
int arr[500], par[5001], tim[500];
bool dp[5001];
int main(){
    int t,n,d;
    scanf("%d%d",&t,&n);
    for(int i=0;i<=t;i++)dp[i]= false,tim[i]=-1;
    dp[0]=true;
    for(int i=0;i<n;i++){
        scanf("%d",&d);
        arr[i]=d;
        for(int j=t-d;j>=0;j--){
            if(!dp[j]||dp[j+d])continue;
            dp[j+d]=true;
            par[j+d]=i;
        }
    }
    int lf;
    for( lf=t;lf>=0&&!dp[lf];lf--);
    for(int c=0;lf>0;c+=arr[par[lf]],lf-=arr[par[lf]])tim[par[lf]]=c;
    for(int c=0,i=0;i<n;i++){
        if(tim[i]==-1){
            tim[i]=c;
            c+=arr[i];
        }
        if(i!=0)printf(" ");
        printf("%d",tim[i]);
    }
}