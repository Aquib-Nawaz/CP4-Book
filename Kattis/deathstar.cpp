#include <iostream>
using namespace std;

int main(){
    int t,n,k,p;
    scanf("%d\n", &t);
    for(int i=1; i<=t; i++){
        scanf("%d %d", &n, &k);
        p=1<<n;
        printf("Case #%d: %s\n", i, (k+1)%p==0 ? "ON" : "OFF");
    }
}