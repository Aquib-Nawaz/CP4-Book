#include <iostream>
using namespace std;

#define MAX 14001

bool isPrime[MAX];
int diffFactor[MAX], sum[1<<14], arr[14], dp[1<<14];


void seive(){
    for(int i=0;i<MAX;i++) isPrime[i]= true, diffFactor[i]=0;
    for(int i=2;i<MAX;i++){
        if(!isPrime[i]) continue;
        for(int j=i;j<MAX;j+=i){
            isPrime[j]= false;
            diffFactor[j]++;
        }
    }
    diffFactor[1]=diffFactor[0]=0;
}

int main(){
    int n;
    seive();
    scanf("%d", &n);
    for(int i=0;i<n;i++) scanf("%d", &arr[i]);
    for(int i=0,s;i<(1<<n);i++){
        s=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j)) s+=arr[j];
        }
        sum[i] = diffFactor[s];
    }
    for(int i=0;i<(1<<n);i++){
        dp[i]=sum[i];
        for(int j=i; j>0; j=(j-1)&i) dp[i]=max(dp[i], dp[j]+sum[i^j]);
    }
    printf("%d\n", dp[(1<<n)-1]);
}