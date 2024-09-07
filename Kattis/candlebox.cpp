#include <iostream>
#include <cmath>
using namespace std;

int main(){
    //r - t = d (r-d-2)(r-d+3)
    //(r-3)/2(r+4) + (t-2)/2(t+3) => r2  -12 + r2 + (-2d)r +(d+2)(d-3)
    int d,x,y;
    scanf("%d%d%d", &d,&x,&y);
    int a=1,b=1-d,c=(d+2)*(d-3)/2-6-x-y;
    int r=(-b+sqrt(b*b-4*a*c))/(2*a) +1e-10;
    printf("%d\n", x-(r-3)*(r+4)/2);
}