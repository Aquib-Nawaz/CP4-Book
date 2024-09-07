#include <iostream>
using namespace std;
bool isPrimes[100000];
int primes[100000], cnt=0;

bool isPrime(int n){

    for(int i=0;i<cnt&&primes[i]*primes[i]<=n;i++)
        if(n%primes[i]==0)return false;
    return true;
}

int main(){
    int n;
    for(int i=2;i<100000;i++)isPrimes[i]= true;
    for(int i=2;i*i<100000;i++){
        if(isPrimes[i]){
            for(int j=i*i;j<100000;j+=i){
                isPrimes[j]= false;
            }
        }
    }

    for(int i=2;i<100000;i++)if(isPrimes[i])primes[cnt++]=i;
    while (scanf("%d", &n), n){
        int i;
        for(i=2*n+1;;i+=2)
            if(isPrime(i))break;

        printf("%d", i);
        if(!isPrime(n)){
            printf(" (%d is not prime)", n);
        }
        printf("\n");
    }
}