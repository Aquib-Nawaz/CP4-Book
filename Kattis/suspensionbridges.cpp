#include <iostream>
#include <math.h>

using namespace std;
typedef long double ld;
double s, d;

long double f(long double a){
    return a+s-a*cosh(d/(2*a));
}

int main(){
    scanf("%lf %lf",&d,&s);
    long double lo, hi, mid;
    lo = 0, hi=1e9+10;

    while(hi-lo>1e-10){
        mid = (hi+lo)/2;
        if(f(mid)>0)hi = mid;
        else lo = mid;
    }
    printf("%.8Lf\n",2*lo*sinh(d/(2*lo)));
}