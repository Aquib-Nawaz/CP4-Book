#include <iostream>
using namespace std;

int main(){
    int n,k,b;
    while(scanf("%d %d", &n,&k)!=-1){
        int ans=0;
        b=0;
        while(n){
            ans+=n;
            b+=n;
            n=b/k;
            b%=k;
        }
        printf("%d\n", ans);
    }
}