#include <iostream>
using namespace std;

#define MAX 100000

bool isPrime[MAX];
int prime[10000],sz=0;

void seive(){
    for(int i=0;i<MAX;i++) isPrime[i]= true;
    for(int i=2;i*i<MAX;i++){
        if(!isPrime[i]) continue;
        for(int j=i*i;j<MAX;j+=i){
            isPrime[j]= false;
        }
    }

    for(int i=2;i<MAX;i++){
        if(isPrime[i]) prime[sz++]=i;
    }
}

long long sumDivisors(int n){
    int ret=1;
    int _n = n;
    for(int i=0;prime[i]*prime[i]<=n;i++){
        if(n%prime[i]==0){
            int multiplier=prime[i], tot=1;
            while(n%prime[i]==0){
                n/=prime[i];
                tot+=multiplier;
                multiplier*=prime[i];
            }
            ret*=tot;
            if(_n+2<ret/2) return ret-_n;
        }
    }

    if(n!=1) ret*=n+1;
    return ret-_n;
}

int main(){
    int n;
    seive();
    while (scanf("%d", &n)==1){
        int t = sumDivisors(n);
        if(t==n) printf("%d perfect\n", n);
        else if(abs(t-n)<=2) printf("%d almost perfect\n", n);
        else printf("%d not perfect\n", n);
    }
}