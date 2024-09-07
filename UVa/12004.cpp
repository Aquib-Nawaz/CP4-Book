#include <iostream>
using namespace std;

int main(){
    int N,C=0,T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        long long t = (long long)N*(N-1);
        if(t%4==0)
            printf("Case %d: %lld\n",++C, t/4);
        else
            printf("Case %d: %lld/2\n", ++C, t/2);
    }
}