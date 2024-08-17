#include <iostream>
#include <algorithm>
using namespace std;

int A[10000];
int main(){
    int N,P;
    while(scanf("%d", &N)!=-1){
        for(int i=0;i<N;i++)scanf("%d", &A[i]);
        scanf("%d", &P);
        int ans;
        sort(A,A+N);
        for(int i=0;i<N&&A[i]<=P/2;i++){
            auto it = lower_bound(A+i+1,A+N,P-A[i]);
            if(it!=A+N&&*it==P-A[i]){
                ans = A[i];
            }
        }
        printf("Peter should buy books whose prices are %d and %d.\n\n",ans,P-ans);
    }
}