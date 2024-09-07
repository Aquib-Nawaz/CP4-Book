#include <iostream>
using namespace std;

#define MAX 32001
bool isPrime[MAX];
int primes[MAX], cnt=0, res[1000];

void seive(){
    for(bool &i:isPrime)i= true;
    for(int i=2;i*i<MAX;i++){
        if(isPrime[i]){
            for(int j=i*i;j<MAX;j+=i)isPrime[j]= false;
        }
    }
    primes[0]=2;
    cnt=1;
    for(int i=3;i<MAX;i+=2)if(isPrime[i])primes[cnt++]=i;
}

int main(){
    int T,n;
    scanf("%d", &T);
    seive();
    while (T--){
        scanf("%d", &n);
        int ans=0;
        for(int i=0;i<cnt&&primes[i]<=n/2;i++){
            if(isPrime[n-primes[i]])res[ans++]=primes[i];
        }
        printf("%d has %d representation(s)\n", n, ans);
        for(int i=0;i<ans;i++)printf("%d+%d\n", res[i], n-res[i]);
        printf("\n");
    }
}