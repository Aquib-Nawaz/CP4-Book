#include <iostream>
using namespace std;

int josephus(int n, int k) {
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res = (res + k) % i;
    return res ;
}

int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    printf("%d",josephus(n,k));
    return 0;
}