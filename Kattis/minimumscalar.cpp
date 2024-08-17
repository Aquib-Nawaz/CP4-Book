#include <iostream>
#include <algorithm>
using namespace std;

int A[2][800];

int main(){
    int T,N,d,C=0;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int j=0;j<2;j++)for(int i=0;i<N;i++)scanf("%d", &d),A[j][i]=d;
        for(int i=0;i<2;i++)sort(A[i],A[i]+N);//,sort(B[i],B[i]+SB[i]);
        long long ans=0;
        for(int i=0;i<N;i++)ans+=(long long)A[0][i]*A[1][N-1-i];
        printf("Case #%d: %lld\n",++C ,ans);
    }
}
