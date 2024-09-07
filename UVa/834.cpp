#include <iostream>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b){
    return b?gcd(b,a%b):a;
}

void printContinuedFraction(ll num, ll den) {
    ll g = gcd(num, den), rem;
    num /= g, den /= g;
    rem = (num%den + den)%den;
    bool f  =true;
    printf("[");
    printf("%lld",(num-rem)/den);
    num = den,den=rem;
    while(den){
        rem = num%den;
        printf("%c", f?';':',');
        printf("%lld",(num-rem)/den);
        f=false;
        num = den,den=rem;
    }
    printf("]\n");
}
int main(){
    int a,b;
    while(scanf("%d %d", &a, &b)==2)
        printContinuedFraction(a,b);
}