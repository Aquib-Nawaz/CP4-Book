#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int main(){
    int a;
    while (scanf("%d", &a), a!=0){
        int b, g=-1;
        while (scanf("%d", &b), b!=0){
            if(g==-1)g=abs(b-a);
            else
                g = gcd(g, abs(b-a));
        }
        if(g==-1)g=a;
        printf("%d\n", g);
    }
}