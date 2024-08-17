#include <iostream>
#include <algorithm>
using namespace std;
int A[100000];
int main(){
    int n,m,d;
    scanf("%d %d", &n,&m);
    long long ans=0;
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    sort(A,A+n);
    for(int i=0;i<m;i++){
        scanf("%d",&d);
        ans+=*lower_bound(A,A+n,d)-d;
    }
    printf("%lld",ans);
}