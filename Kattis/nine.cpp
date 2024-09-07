#include <iostream>
using namespace std;

#define PRIME 1000000007

long long pow(long long y){
    if(y==0)return 1;
    long long ans = pow(y/2);
    ans = ans*ans%PRIME;
    if(y%2==0)return ans;
    else return ans*9%PRIME;
}

int main(){
    int T;
    scanf("%d", &T);
    while (T--){
        long long d;
        scanf("%lld", &d);
        printf("%lld\n", pow(d-1)*8%PRIME);
    }
}