#include <iostream>
#include <algorithm>
using namespace std;
int A[1000000];
int main(){
    int T,C=0;
    scanf("%d",&T);
    while(T--){
        int n,k,d;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)scanf("%d",A+i);
        for(int i=0;i<n;i++)scanf("%d",&d),A[i]=d-A[i];
        long long ans=0;
        sort(A,A+n,greater<int>());
        for(int i=0;i<n&&(n-i>k||A[i]>0);i++)ans+=A[i];
        printf("Case %d: ", ++C);
        if(ans<=0)printf("No Profit\n");
        else printf("%lld\n",ans);
    }
}