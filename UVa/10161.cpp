#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int N;
    while(scanf("%d",&N),N){
        int sq = sqrt(N)+1e-15;
        int rem = N-sq*sq;
        int r,c;
        if(rem==0){
            r=1,c=sq;
        }
        else if(rem<=sq+1){
            r=rem,c=sq+1;
        }
        else {
            r=sq+1,c=2*(sq+1)-rem;
        }
        if((sq&1)==0)swap(r,c);
        printf("%d %d\n",r,c);
    }

}