#include <iostream>
#include <algorithm>
using namespace std;
int arr[10000],L[10000],dp[10000];
int main(){
    int N,k,pos,ans;

    while(scanf("%d",&N)!=-1){
        for(int i=0;i<N;i++)scanf("%d",arr+i);
        k=0;
        for(int i=0;i<N;i++){
            pos = lower_bound(L,L+k,arr[i])-L;
            dp[i]=pos;
            L[pos]=arr[i];
            if(pos==k)k++;
        }
        k=ans=0;
        for(int i=N-1;i>=0;i--){
            pos = lower_bound(L,L+k,arr[i])-L;
            L[pos]=arr[i];
            if(pos==k)k++;
            ans = max(ans, 2*min(dp[i],pos)+1);
        }
        printf("%d\n",ans);
    }



}