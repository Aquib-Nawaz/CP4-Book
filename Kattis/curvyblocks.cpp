#include <iostream>
#include <cmath>
using namespace std;

typedef long double ld;
ld a,b,c,d;
ld eval(ld x){
    return d*x*x*x + c*x*x + b*x + a;
}
int main(){
    while (scanf("%LF%LF%LF%LF",&a,&b,&c,&d)!=EOF){
        ld _a,_b,_c,_d;
        scanf("%LF%LF%LF%LF",&_a,&_b,&_c,&_d);
        a=_a-a,b=_b-b,c=_c-c,d=_d-d;
        _a = max(a,a+b+c+d), _b = min(a,a+b+c+d);
        if(abs(d)>1e-10){
            ld D = 4*c*c-12*b*d;
            if(D>0){
                ld x1 = (-2*c+sqrt(D))/(6*d), x2 = (-2*c-sqrt(D))/(6*d);
                if(x1>0 && x1<1)_a = max(_a, eval(x1)), _b = min(_b, eval(x1));
                if(x2>0 && x2<1)_a = max(_a, eval(x2)), _b = min(_b, eval(x2));
            }
        }
        else if(abs(c)>1e-10){
            ld x = -b/(2*c);
            if(x>0 && x<1)_a = max(_a, eval(x)), _b = min(_b, eval(x));
        }
        printf("%.10LF\n",_a-_b);
    }
}