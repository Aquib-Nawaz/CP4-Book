#include <iostream>
using namespace std;

int main(){
    int T;
    long long Tm,V,D,ans;
    scanf("%d",&T);
    while (T--){
        scanf("%lld %lld %lld",&Tm,&V,&D);
        ans = D*1000000/(Tm*86400);
        printf("%s %lld tons\n",ans>0?"Remove":"Add", abs(ans));
    }
}