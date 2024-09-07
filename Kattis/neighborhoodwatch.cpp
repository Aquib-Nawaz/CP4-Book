#include <iostream>
using namespace std;

int main(){
    int N,H;
    scanf("%d%d", &N,&H);
    long long ans = (long long)N*(N+1)/2;
    int last = 0,cur;
    for(int i=0;i<H;i++){
        scanf("%d", &cur);
        ans-=(long long)(cur-last-1)*(cur-last)/2;
        last=cur;
    }
    cur = N+1;
    ans-=(long long)(cur-last-1)*(cur-last)/2;
    printf("%lld\n", ans);
}