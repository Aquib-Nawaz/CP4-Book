#include <iostream>
#include <cmath>
using namespace std;

double pow(double x, int y){
    if(y==0)return 1;
    double ans = pow(x,y/2);
    if (y%2 == 0) return ans*ans;
    else return ans*ans*x;
}

int main(){
    int X,Y,N;
    double r;
    while (scanf("%d%d%d%lf",&X,&Y,&N,&r),X) {
        bool yes;
        if(r<1e-10)yes = (long long)Y*N*12>=X;
        else {
            r /= 1200;
            double po = pow(1 + r, 12 * N), pi = po * X, payed = (po - 1) * Y / r;
            yes = payed >= pi;
        }
        printf("%s\n", yes?"YES":"NO");
    }
}