#include <iostream>
#include <unordered_map>
using namespace std;

#define MAX 432
unordered_map<int,int> factors[MAX];

void findFactors(int n){
    int i=n;
    for(int j = 2;j*j<=i;j++) {
        if(i%j==0){
            int cnt=0;
            while(i%j==0){
                i/=j;
                cnt++;
            }
            factors[n][j]=cnt;
        }
    }
    if(i>1) factors[n][i]=1;
}

void init() {
    for (int i = 2; i < MAX; i++) {
        findFactors(i);
    }

    for (int i = 3; i < MAX; i++) {
        for( auto it: factors[i-1]){
            factors[i][it.first]+=it.second;
        }
    }
}

int main() {
    int n,k;
    init();
    while (scanf("%d%d", &n, &k) == 2) {
        long long ret=1;
        for(auto it: factors[n]){
            ret*= it.second - factors[k][it.first] - factors[n-k][it.first] + 1;
        }
        printf("%lld\n", ret);
    }
}