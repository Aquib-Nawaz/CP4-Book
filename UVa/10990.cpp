#include <iostream>
using namespace std;

#define MAX 2000001

bool isPrime[MAX];
int diffFactors[MAX];

void seive(){
    for(int i=0;i<MAX;i++) isPrime[i]= true, diffFactors[i]=i;
    for(int i=2;i<MAX;i++){
        if(!isPrime[i]) continue;
        for(int j=i;j<MAX;j+=i){
            isPrime[j]= false;
            diffFactors[j]-= diffFactors[j] / i;
        }
    }
    diffFactors[1]= diffFactors[0]=0;
    for(int i=2;i<MAX;i++) diffFactors[i]= 1 + diffFactors[diffFactors[i]];
    for(int i=2;i<MAX;i++) diffFactors[i]+=diffFactors[i - 1];
}

int main(){
    int T;
    scanf("%d", &T);
    seive();
    while(T--){
        int n,m;
        scanf("%d%d", &n, &m);
        printf("%d\n", diffFactors[m] - diffFactors[n - 1]);
    }
}