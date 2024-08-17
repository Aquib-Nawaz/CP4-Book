#include <iostream>
using namespace std;
int A[100001];

bool can(int x, int n){
    for(int i=1;i<=n;i++)
        if(A[i]>x)return false;
        else if(A[i]==x)x--;
    return true;
}

int main(){
    int T,n,hi,lo,mid,ans,C=0;
    scanf("%d", &T);
    A[0]=0;
    while(T--){
        scanf("%d", &n);
        for(int i=1;i<=n;i++)scanf("%d", &A[i]);
        lo=1;
        for(int i=n;i>=1;i--)A[i]-=A[i-1],lo=max(lo,A[i]);
        hi=lo+1;
        while(hi>=lo){
            mid=(hi+lo)>>1;
            if(can(mid,n))ans=mid,hi=mid-1;
            else lo=mid+1;
        }
        printf("Case %d: %d\n",++C, ans);
    }
}