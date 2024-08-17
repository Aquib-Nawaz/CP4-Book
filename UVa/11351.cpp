#include <iostream>
using namespace std;

int josephus(int n, int k) {
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res = (res + k) % i;
    return res+1 ;
}

int main(){
    int T,C=0;
    scanf("%d",&T);
    while(T--){
        int n,k;
        scanf("%d %d",&n,&k);
        printf("Case %d: %d\n",++C,josephus(n,k));
    }
}