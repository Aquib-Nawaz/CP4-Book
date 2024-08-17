#include <iostream>
#include <cmath>
using namespace std;

typedef long double ld;
int A[30];
int main() {
    int n, req = 2;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)scanf("%d", A + i);
    ld ans=0,l=pow(2,-3.0/4),s=pow(2,-5/4.0),t;
    for (int i = 0; i < n && req>0; i++) {
        ans+=l*req/2;
        req=2*(req-A[i]);
        t=l;
        l=s;
        s=t/2;
    }
    if(req>0)printf("impossible");
    else
        printf("%Lf", ans);
}