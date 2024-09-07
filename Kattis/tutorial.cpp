#include <iostream>
#include <cmath>
using namespace std;

double timecomplexity(int n, int t){
    switch (t) {
        case 1:{
            double ret=0;
            for(int i=2;i<=400&&i<=n;i++)ret+=log(i);
            return ret;
        }
        case 2:
            return n*log(2);
        case 3:
            return 4*log(n);
        case 4:
            return 3*log(n);
        case 5:
            return 2*log(n);
        case 6:
            return log(n)+log(log2(n));
        case 7:
            return log(n);
        default:
            return 0;
    }
}

int main(){
    int m,n,t;
    scanf("%d %d%d" , &m,&n,&t);
    bool ac = log(m)+1e-10 >= timecomplexity(n,t);
    printf("%s\n" , ac?"AC":"TLE");
}