#include <cmath>
#include <iostream>

using namespace std;
typedef struct {
    int h=0,v=0;
}P;
int a,b,v,A,s;

P solve(){
    double d = 0.5*s*v;
    P ret;
    if(A==90){
        ret.h=  (d+b/2)/b;
        return ret;
    }
    else if(A==0){
        ret.v=  (d+a/2)/a;
        return ret;
    }
    double Ar = A*M_PI/180;
    double hl=a/2.0,vl=b/2.0;
    while(true){
        double t = min(hl/cos(Ar),vl/sin(Ar));
        if(t<d){
            d-=t;
            hl-=t*cos(Ar);
            vl-=t*sin(Ar);
        }
        else
            break;
        if(abs(hl)<1e-10)
            ret.v++,hl=a;
        if(abs(vl)<1e-10)
            ret.h++,vl=b;
    }
    return ret;

}

int main() {
    while (scanf("%d %d %d %d %d",&a,&b,&v,&A,&s),a) {
        P p=solve();
        printf("%d %d\n",p.v,p.h);
    }
}