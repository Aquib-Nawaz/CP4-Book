#include <iostream>
using namespace std;

#define MAX 10001
bool isPrime[MAX];
int primes[MAX],cnt=0;

void seive(){
    for(bool &i:isPrime)i= true;
    isPrime[1]= false;
    for(int i=2;i*i<MAX;i++){
        if(isPrime[i]){
            for(int j=i*i;j<MAX;j+=i)isPrime[j]= false;
        }
    }
    for(int i=2;i<MAX;i++)if(isPrime[i])primes[cnt++]=i;
}

int main(){
    int n;
    seive();
    while (scanf("%d", &n), n){
        int count=0;
        for(int r=0,l=0, cur=0;r<cnt&&primes[r]<=n;r++){
            cur+=primes[r];
            while(cur>n){
                cur-=primes[l];
                l++;
            }
            if(cur==n)count++;
        }
        printf("%d\n", count);
    }
}