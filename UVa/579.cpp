#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int h, m;
    while(scanf("%d:%d", &h, &m),(h||m)){
        double ha = (h+m/60.0)*30;
        double ma = m*6;
        double d = abs(ha-ma);
        if(d>180) d = 360-d;
        printf("%.3lf\n", d);
    }
}