#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int T,n;
    scanf("%d",&T);

    while (T--){
        scanf("%d", &n);
        long long res=0;
        if(n>0) {
            int sq = sqrt(n);
            for (int i = 1; n / i > sq; i++)res += n / i;
            for (int i = 1; i <= sq; i++)
                res += (long long) i * (n / i - n / (i + 1));
        }
        printf("%lld\n",res);
    }
}