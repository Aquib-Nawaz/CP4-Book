#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double b = log2(3),hi,lo;
    long long ans,t,m;
    while (scanf("%lld",&m),m){
        if((m&-m)==m){
            printf("%lld\n" ,m);
            continue;
        }
        hi = ceil(log2(m));
        lo = log2(m);
        ans=1LL<<(int)hi;
        for(int i=lo,j;i>=0;i--){
            j = floor((hi-i)/b);
            t = (1LL<<i)*(pow(3,j));
            if(t>=m && t-m<ans-m)ans=t;
        }
        printf("%lld\n",ans);
    }
}
