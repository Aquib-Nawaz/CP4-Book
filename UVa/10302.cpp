#include <iostream>
using namespace std;

typedef long long ll;

ll fac(ll x, int k){
    ll ret=1;
    while(k--){
        ret*=x, x--;
    }
    return ret;
}

int main(){
    ll N;
    while(scanf("%lld", &N)==1){
        N++;
        printf("%lld\n", fac(N,4)/4+fac(N,3)+fac(N,2)/2);
    }

}