#include <iostream>
using namespace std;
#define MAX 10000001
bool isPrime[MAX];
int primes[700000], sz=0;

void sieve(){
    for(bool & i : isPrime) i=true;
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<MAX;i++){
        if(isPrime[i]){
            for(int j=i*i;j<MAX;j+=i) isPrime[j]=false;
        }
    }
    for(int i=2;i<MAX;i++) if(isPrime[i]) primes[sz++]=i;
}

long long solve(long long n){
    long long t=n;
    long long ret=-1;
    bool f=false;
    for(int i=0;i<sz&&((long long)primes[i]*primes[i]<=t);i++){
        if(t%primes[i]==0){
            if(ret!=-1)f=true;
            ret=primes[i];
            while(t%primes[i]==0)
                t/=primes[i];
        }
    }
    if(t!=1 && ret!=-1) ret=t, f=true;
    if(!f) ret=-1;
    return ret;
}

int main(){
    sieve();
    long long n;
    while(scanf("%lld",&n),n){
        printf("%lld\n",solve(abs(n)));
    }
}