#include <iostream>
#include <algorithm>
using namespace std;

int primes[100000];
bool isPrime[1299710];

int main(){
    for(int i=0;i<=1299709;i++)isPrime[i]=true;
    int cnt=0;
    for(int i=2;i<=1299709;i++){
        if(isPrime[i]){
            primes[cnt++]=i;
            for(int j=2*i;j<=1299709;j+=i)isPrime[j]=false;
        }
    }
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0)break;
        int lb = lower_bound(primes, primes+cnt, n)-primes;
        if(primes[lb]==n)printf("0\n");
        else {
            printf("%d\n", primes[lb]-primes[lb-1]);
        }
    }
}