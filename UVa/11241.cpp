#include <iostream>
#include <cmath>
using namespace std;
typedef long double ld;
ld t,h,d;

ld fe(){
    return 6.11 * exp(5417.7530 * ((1/273.16) - (1/(d + 273.16))));
}

ld fh(){
    return (0.5555)*(fe() - 10.0);
}

ld invh(){
    return h-t;
}

ld inve(){
    return invh()/0.5555 + 10.0;
}

void getD(){
    d = 1/((1/273.16) - log(inve()/6.11)/5417.7530)-273.16;
}

void getH(){
    h = fh()+t;
}

void getT(){
    t = h-fh();
}



int main(){
    char c;
    while (scanf(" %c", &c),c!='E'){
        int i;
        ld temp;
        scanf("%LF", &temp);
        if(c=='T')i=1, t=temp;
        else if(c=='H')i=2, h=temp;
        else i=4, d=temp;
        scanf(" %c", &c);
        scanf("%Lf", &temp);
        if(c=='T')t=temp, i^=1;
        else if(c=='H')h=temp, i^=2;
        else d=temp, i^=4;
        if((i&1) == 0)getT();
        if((i&2) == 0)getH();
        if((i&4) == 0)getD();
        printf("T %.1LF D %.1LF H %.1LF\n", t,d,h);
    }
}