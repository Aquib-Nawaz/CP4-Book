#include <iostream>
using namespace std;

int main(){
    int n;
    scanf("%d", &n);
    long long l1 = n/2+1+n%2,l2 = n/2+1;
    printf("%lld\n", l1*l2);
}
