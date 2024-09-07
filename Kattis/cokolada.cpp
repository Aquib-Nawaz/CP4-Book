#include <iostream>
using namespace std;

int ceillog2n(int n){
    return 32-__builtin_clz(n-1);
}

int main(){
    int n;
    scanf("%d", &n);
    int l = ceillog2n(n), r=__builtin_ctz(n);
    printf("%d %d", 1<<l, l-r);
}