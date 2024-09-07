#include <iostream>
using namespace std;

int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        int n,m;
        scanf("%d%d", &n,&m);
        long long ans = (long long)n*(2*m-1-n)/2;
        printf("%lld\n", ans);
    }
}