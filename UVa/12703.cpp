#include <iostream>
#include <map>
using namespace std;
#define MAX 40
bool isPrime[40];
int prime[20], cnt=0, dp[41];

void primeFactors(int x, int m, map<int,int>& factors){
    for(int i=0; i<cnt && prime[i]*prime[i]<=x; i++){
        while(x%prime[i]==0){
            factors[prime[i]]+=m;
            x/=prime[i];
        }
    }
    if(x>1) factors[x]+=m;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int  i=2; i<MAX; i++) isPrime[i]= true;
    for(int i=2; i<MAX; i++){
        if(isPrime[i]){
            for(int j=i+i; j<MAX; j+=i) isPrime[j]= false;
        }
    }
    for(int i=2; i<MAX; i++) if(isPrime[i]) prime[cnt++]=i;
    dp[0]=0,dp[1]=1;
    for(int i=2; i<=40; i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    while(T--){
        int n,a,b;
        scanf("%d %d %d", &n, &a, &b);
        map<int,int>factors;
        primeFactors(a,dp[n-1],factors);
        primeFactors(b,dp[n],factors);
        for(auto p: factors) printf("%d %d\n", p.first, p.second);
        printf("\n");
    }
}