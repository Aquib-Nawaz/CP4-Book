#include <iostream>
#include <cstring>
using namespace std;

int arr[100];
bool dp[100][64001];
char par[100][64001], tmp[100];

int getidx(int v){
    if(v<=32000 && v>=-32000) return v+32000;
    return -1;
}

int main(){
    int T,n, t, id,v;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%d",arr+i);
        scanf("%d",&v);
        memset(dp, 0, sizeof dp);
        dp[0][arr[0]+32000]=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<64001;j++){
                if(!dp[i-1][j])continue;
                t=j-32000;
                id = getidx(t+arr[i]);
                if(id!=-1)dp[i][id]=true, par[i][id]='+';
                id = getidx(t-arr[i]);
                if(id!=-1)dp[i][id]=true, par[i][id]='-';
                id = getidx(arr[i]*t);
                if(id!=-1)dp[i][id]=true, par[i][id]='*';
                id = getidx(t/arr[i]);
                if(id!=-1 && t%arr[i]==0)dp[i][id]=true, par[i][id]='/';
            }
        }
        char c;
        if(!dp[n-1][v+32000]){
            printf("NO EXPRESSION\n");
            continue;
        }
        else {
            for(int i=n-1,cur=v;i>0;i--){
                c=par[i][cur+32000];
                if(c=='-')cur+=arr[i];
                if(c=='+')cur-=arr[i];
                if(c=='*')cur/=arr[i];
                if(c=='/')cur*=arr[i];
                tmp[i]=c;
            }
            printf("%d", arr[0]);
            for(int i=1;i<n;i++)printf("%c%d",tmp[i],arr[i]);
            printf("=%d\n",v);
        }
    }
}