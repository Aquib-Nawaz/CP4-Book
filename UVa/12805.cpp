#include <iostream>
using namespace std;

#define MAX 100001
bool isPrime[MAX];
int primes[10000],cnt=0;

int sign(int x){
    if(x%4==3||x==2)return 1;
    return -1;
}

int main(){
    for(int i=2;i<MAX;i++)isPrime[i]=true;
    for(int i=2;i<MAX;i++){
        if(isPrime[i]){
            for(int j=i+i;j<MAX;j+=i)isPrime[j]=false;
        }
    }
    for(int i=2;i<MAX;i++)if(isPrime[i])primes[cnt++]=i;
    int T,n;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        int c=1;
        for(int i=0;i<cnt&&primes[i]*primes[i]<=n;i++){
            while(n%primes[i]==0)n/=primes[i],c*=sign(primes[i]);
        }
        if(n>1)c*=sign(n);
        cout<<(c==1?'+':'-')<<endl;
    }
}