#include <iostream>
using namespace std;

#define MAX 2000001

bool isPrime[MAX];
int diffFactor[MAX];

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
    while(scanf("%d", &n),n){
        printf("%d : %d\n",n, diffFactor[n]);
    }
}