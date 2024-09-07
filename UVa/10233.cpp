#include <iostream>
#include <cmath>
using namespace std;

void getrc(int n, int &r, int &c){
    r = (int) sqrt(n)+1;
    c = n-(r-1)*(r-1)+1;
}

int main(){
    int n,m;
    int r1,c1,r2,c2;
    while (scanf("%d%d", &n,&m)==2){
        if(n>m)swap(n,m);
        getrc(n,r1,c1);
        getrc(m,r2,c2);
        long double b =(c2-r2-c1+r1)/2.0, h = sqrt(3)*(r2-r1)/2;
        h-=((c1&1)-(c2&1))*(1/(2*sqrt(3)));
        printf("%.3Lf\n", sqrt(b*b+h*h));
    }
}