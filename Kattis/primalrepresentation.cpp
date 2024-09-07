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
    while (scanf("%d", &n)==1){
        bool f=true;
        if(n<0)n=-n, printf("-1"), f=false;
        for(int i=0;(long long)primes[i]*primes[i]<=n;i++){
            int c=0;
            while(n%primes[i]==0){
                c++;
                n/=primes[i];
            }
            if(c==0)continue;
            if(!f) printf(" ");
            else f=false;
            printf("%d", primes[i]);
            if(c>1){
                printf("^%d", c);
            }
        }
        if(n>1){
            printf("%s%d", f?"":" ", n);
        }
        printf("\n");
    }

}