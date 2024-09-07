#include <iostream>
using namespace std;
#define MAX 100000
bool isPrime[MAX];
int primes[10000], sz=0;

void sieve(){
    for(int i = 0; i < MAX; i++){
        isPrime[i] = true;
    }
    for(int i = 2; i * i < MAX; i++){
        if(isPrime[i]){
            for(int j = i * i; j < MAX; j += i){
                isPrime[j] = false;
            }
        }
    }
    for(int i = 2; i < MAX; i++){
        if(isPrime[i]){
            primes[sz++] = i;
        }
    }
}

int eulerTotient(int n) {
    int ret=n;
    for (int i = 0; i < sz && primes[i] * primes[i] <= n; i++) {
        if(n%primes[i] == 0) {
            while(n%primes[i] == 0) {
                n /= primes[i];
            }
            ret -= ret/primes[i];
        }
    }
    if(n > 1) ret -= ret/n;
    return ret;
}
int main(){
    int n;
    sieve();
    while(cin >> n, n){
        printf("%d\n", eulerTotient(n));
    }
}