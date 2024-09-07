#include <iostream>
using namespace std;

int gcd(int a, int b){
    if(b==0)return a;
    return gcd(b,a%b);
}

int main(){
    int n;
    scanf("%d", &n);
    int a,b,g;
    scanf("%d", &a);
    for(int i=1;i<n;i++){
        scanf("%d", &b);
        g = gcd(a,b);
        printf("%d/%d\n", a/g, b/g);
    }
}