#include <iostream>
using namespace std;

int A[25],B[25];

int main(){
    int n,d, ans;
    while(scanf("%d",&n)!=-1){
        ans=0;
        for(int i=1;i<=n;i++)scanf("%d", &d), A[d]=i;
        for(int i=1;i<=n;i++)scanf("%d", &d), B[d]=i;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans+=A[i]<A[j]!=B[i]<B[j];
            }
        }
        printf("%d\n", ans);
    }
}