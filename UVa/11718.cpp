#include <iostream>
using namespace std;

int M;

long long pow(int n,int k){
    if(k==0)return 1;
    long long temp = pow(n,k/2);
    temp = temp*temp%M;
    if(k%2==1)temp = temp*n%M;
    return temp;
}

int main(){
    int n,k,T,C=0;
    scanf("%d", &T);
    while (T--){
        scanf("%d%d%d", &n, &k, &M);
        long long sum = 0;
        int d;
        for(int i=0;i<n;i++)scanf("%d", &d),sum+=d;
        sum = sum%M;
        sum = (pow(n,k-1)*k%M)*sum%M;
        printf("Case %d: %lld\n",++C, sum);
    }
}