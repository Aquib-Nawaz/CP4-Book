#include <iostream>
using namespace std;
#define MAX 2000001
bool isPrime[MAX];
int factors[MAX];
int primeFactors[MAX];

void sieve(){
    for(int i=2;i<MAX;i++){
        isPrime[i]=true;
        primeFactors[i]=0,factors[i]=1;
    }
    for(int i=2;i<MAX;i++){
        if(isPrime[i]){
            factors[i]=2;
            primeFactors[i]=1;
            for(int j=2*i;j<MAX;j+=i){
                isPrime[j]=false;
                int cnt=0,_j=j;
                while (_j%i==0) _j/=i, cnt++;
                primeFactors[j]++;
                factors[j]*=cnt+1;
            }
        }
    }

}


int main(){
    sieve();
    int Q;
    scanf("%d", &Q);
    while(Q--){
        int n;
        scanf("%d", &n);
        printf("%d\n", factors[n]-primeFactors[n]);
    }
}