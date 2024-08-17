#include <iostream>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    long long n;
    while(T--){
        scanf("%lld", &n);
        printf("%d\n", __builtin_popcountll(n));
    }
}