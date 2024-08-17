#include <iostream>
using namespace std;

#define MAXN 1121

int primes[200],sz=0, dp[MAXN][15];

bool isPrime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0)return false;
    }
    return true;
}

void getPrime(){
    for(int i=2;i<MAXN; i++){
        if(isPrime(i))primes[sz++]=i;
    }
}

int main(){
    int n,k;
    getPrime();
    for(int i=1;i<MAXN;i++)dp[i][0]=0;
    dp[0][0]=1;
    for(int i=0;i<sz;i++){//200
        for(int j=MAXN-1;j>=0;j--)
            for(int t = 1; t<=14;t++){
                if(j+primes[i]<MAXN){
                    dp[j+primes[i]][t] += dp[j][t-1];
                }
            }
    }

    while(scanf("%d%d",&n,&k),n||k){
        printf("%d\n",dp[n][k]);
    }
}