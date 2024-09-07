#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int x;
    while(scanf("%d",&x)==1){
        int n = log10(x)+2;
        long double lgx = log2(x), lgx1 = log2(x+1), lg10 = log2(10),lhs,rhs;
        while(true){
            lhs = lgx + n*lg10;
            rhs = lhs - lgx + lgx1;
            if((int)lhs<(int)rhs)break;
            n++;
        }
        printf("%d\n",(int)rhs);
    }
}