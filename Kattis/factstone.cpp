#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    while (scanf("%d", &n),n){
        int nbitslog2n = n/10-196+2;
        //find x such that log of log factorial(x) <= nbitslog2n
        long double x = 0;
        int i;
        for(i=2;;i++){
            x+=log2(i);
            if(log2(x)>=nbitslog2n)break;
        }
        printf("%d\n",i-1);
    }
}