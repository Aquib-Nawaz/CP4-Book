#include <iostream>
using namespace std;
#define MAX 100000
int primes[10000],sz=0;
bool isPrime[MAX];

void sieve(){
    for(bool & i : isPrime) i=true;
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<MAX;i++){
        if(isPrime[i]){
            for(int j=i*i;j<MAX;j+=i) isPrime[j]=false;
        }
    }

    for(int i=0;i<MAX;i++){
        if(isPrime[i]) primes[sz++]=i;
    }
}

int solve(int n){
    int ret=1;
    for(int _i=0,i=2;(long long)primes[_i]*primes[_i]<=n;i=primes[++_i]){
        if(n%i==0){
            int cnt=0;
            while(n%i==0){
                n/=i;
                cnt++;
            }
            ret*=2*cnt+1;
        }
    }
    if(n>1) ret*=3;
    return (ret+1)/2;
}

int main(){
    int n;
    sieve();
    while(scanf("%d",&n),n){
        printf("%d %d\n",n, solve(n));
    }
}