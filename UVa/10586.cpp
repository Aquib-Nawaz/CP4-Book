#include <iostream>
using namespace std;
typedef long long ll;
ll coeff[10001];
int main(){
    int N,K;
    while (scanf("%d%d", &N,&K),N!=-1){
        for(int i=0;i<=N;i++)scanf("%lld", &coeff[i]);
        if(K==0){
            printf("0\n");
            continue;
        }
        for(int i=N;i>=K;i--){
            coeff[i-K] -= coeff[i];
        }
        int i;
        for(i=min(K-1,N);i>0&&coeff[i]==0;i--);
        for(int j=0;j<i;j++)printf("%lld ",coeff[j]);
        printf("%lld\n",coeff[i]);
    }
}