#include <iostream>
using namespace std;
#define MAX 1000001
long long fac[MAX];
// Lol it worked
// 5^9 > 1e6
// So we need 9 powers of 2 to divide by 10
// Now 2^9 * 10 < 10000
void init(){
    fac[0] = 1;
    for(int i = 1; i < MAX; i++){
        fac[i] = fac[i-1] * i;
        while(fac[i] % 10 == 0) fac[i] /= 10;
        fac[i] %= 10000;
    }
}

int main(){
    int n;
    init();
    while (scanf("%d", &n) , n){
        printf("%lld\n", fac[n] % 10);
    }
}