#include <iostream>
using namespace std;
#define MAX 100000
bool isPrime[MAX];
int primes[10000], cnt=0;

int main(){
    for(int i=2;i<MAX;i++)isPrime[i]=true;
    for(int i=2;i*i<MAX;i++){
        if(isPrime[i]){
            for(int j=i*i;j<MAX;j+=i)isPrime[j]=false;
        }
    }
    for(int i=2;i<MAX;i++)if(isPrime[i])primes[cnt++]=i;
    int n,c;
    while (scanf("%d", &c),c!=4){
        int count=0;
        do{
            n=c;
            c=0;
            count++;
            for(int i=0;(long long)primes[i]*primes[i]<=n;i++){
                while(n%primes[i]==0){
                    c+=primes[i];
                    n/=primes[i];
                }
            }
            if(c==0)break;
            if(n>1){
                c+=n;
            }
        }while(true);

        printf("%d %d\n", n,count);
    }

}
