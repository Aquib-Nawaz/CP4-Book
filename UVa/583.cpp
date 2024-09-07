#include <iostream>
using namespace std;
#define MAX 100000
bool isPrime[MAX];
int primes[10000], cnt=0, res[35];

int main(){
    for(int i=2;i<MAX;i++)isPrime[i]=true;
    for(int i=2;i*i<MAX;i++){
        if(isPrime[i]){
            for(int j=i*i;j<MAX;j+=i)isPrime[j]=false;
        }
    }
    for(int i=2;i<MAX;i++)if(isPrime[i])primes[cnt++]=i;
    int n;
    while (scanf("%d", &n),n){
        printf("%d = ", n);
        int c=0;
        if(n<0)n=-n, res[c++]=-1;
        for(int i=0;(long long)primes[i]*primes[i]<=n;i++){
            while(n%primes[i]==0){
                res[c++]=primes[i];
                n/=primes[i];
            }
        }
        if(n>1){
            res[c++]=n;
        }
        for(int i=0;i<c;i++){
            if(i)printf(" x ");
            printf("%d", res[i]);
        }
        printf("\n");
    }

}