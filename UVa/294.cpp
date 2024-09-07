#include <iostream>
using namespace std;
#define MAX 100001
bool isPrime[MAX];
int prime[10000], cnt=0;
void sieve(){
    for(int i=2;i<MAX;i++){
        isPrime[i]=true;
    }
    for(int i=2;i<MAX;i++){
        if(isPrime[i]){
            for(int j=2;i*j<MAX;j++){
                isPrime[i*j]=false;
            }
        }
    }

    for(int i=2;i<MAX;i++)
        if(isPrime[i]) prime[cnt++]=i;
}

int numDivisor(int n){
    int ans=1;
    for(int i=0;prime[i]*prime[i]<=n;i++){
        int cnt=0;
        if(n%prime[i]==0){
            while(n%prime[i]==0){
                n/=prime[i];
                cnt++;
            }
            ans*=(cnt+1);
        }
    }
    if(n!=1) ans*=2;
    return ans;
}

int main(){
    int T;
    sieve();
    scanf("%d", &T);
    while (T--){
        int n,m;
        scanf("%d%d", &n,&m);
        int ans=n,num= numDivisor(n);
        for(int i=n+1;i<=m;i++){
            int temp = numDivisor(i);
            if(temp>num){
                ans=i;
                num=temp;
            }
        }
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", n,m,ans,num);
    }
}