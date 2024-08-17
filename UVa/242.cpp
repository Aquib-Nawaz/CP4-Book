#include <iostream>
#include <cstring>
using namespace std;

int arr[11], ans[11];
bool dp[11][1000];

bool less_arr(){
    if(arr[0]!=ans[0])return arr[0]<ans[0];
    for(int i=arr[0];i>0;i--){
        if(arr[i]!=ans[i])return arr[i]<ans[i];
    }
    return false;
}

int main(){
    int n,s, d, mx;
    while(scanf("%d",&s),s){
        scanf("%d",&n);
        mx=-1;
        for(int _=0;_<n;_++){
            scanf("%d",&arr[0]);
            for(int i=1;i<=arr[0];i++)scanf("%d",arr+i);
            memset(dp,0,sizeof dp);
            dp[0][0]=true;
            for(int i=1;i<=arr[0];i++){
                for(int t=1;t<=s;t++)
                    for(int j=arr[i];j<=s*arr[arr[0]];j++)
                        if(dp[t-1][j-arr[i]] || dp[t-1][j])dp[t][j]=true;
            }
            int cur;
            for(cur=1;dp[s][cur];cur++);
            cur--;
            if(cur > mx || cur==mx && less_arr()) {
                mx=cur;
                for(int i=0;i<=arr[0];i++)ans[i]=arr[i];
            }
        }
        printf("max coverage = %3d :",mx);
        for(int i=1;i<=ans[0];i++)printf("%3d",ans[i]);
        printf("\n");
    }
}