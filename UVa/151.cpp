#include <iostream>
using namespace std;

int josephus(int n, int k) {
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res = (res + k) % i;
    return res+2 ;
}

int main(){
    int N,d;
    while(scanf("%d",&N),N){
        for(int m=1;;m++){
            d=josephus(N-1,m);
            if(d==13){
                printf("%d\n",m);
                break;
            }
        }
    }
}