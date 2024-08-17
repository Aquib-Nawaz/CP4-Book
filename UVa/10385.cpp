#include <iostream>
#include <cmath>
using namespace std;

typedef long double ld;

struct {
    ld a,b;
}C[20];

int t, n;
ld f(ld x){
    ld m=1e9;
    for(int i=0;i<n-1;i++)m = min(m,x/C[i].a+(t-x)/C[i].b);
    return 3600*(m-(x/C[n-1].a+(t-x)/C[n-1].b));
}

int main(){
    ld lo,hi,m1,m2,t1;
    while (scanf("%d %d",&t,&n)!=-1){
        for(int i=0;i<n;i++)scanf("%Lf %Lf",&C[i].a,&C[i].b);
        lo=0,hi=t;
        while(hi-lo>=1e-4){
            m1=(2*lo+hi)/3,m2=(lo+2*hi)/3;
            if(f(m1)<f(m2))lo=m1;
            else hi=m2;
        }
        t1=max(f(lo),f(hi));
        if(t1<0)printf("The cheater cannot win.\n");
        else {
            printf("The cheater can win by %d seconds with r = %.2Lfkm and k = %.2Lfkm.\n",(int)round(t1),lo,t-lo);
        }
    }
}