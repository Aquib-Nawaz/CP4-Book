#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main(){
    int T;
    scanf("%d", &T);

    while(T--){
        int g,l;
        scanf("%d %d", &g, &l);
        if(gcd(g,l)!=g)printf("-1\n");
        else{
            printf("%d %d\n", g,l);
        }
    }
}