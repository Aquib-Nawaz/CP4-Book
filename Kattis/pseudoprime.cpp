#include <iostream>
using namespace std;

long long pow(int x, int y, int p){
    if(y==0) return 1;
    long long res = pow(x, y/2, p);
    res = (res*res)%p;
    if(y%2) res = (res*x)%p;
    return res;
}

bool isPrime(int x){
    if(x<=1) return false;
    if(x==2) return true;
    if(x%2==0) return false;
    for(int i=3; i*i<=x; i+=2){
        if(x%i==0) return false;
    }
    return true;
}

int main(){
    int a,p;
    while (scanf("%d%d", &p,&a),a&&p){
        printf("%s\n", pow(a,p,p)==a&&!isPrime(p)?"yes":"no");
    }

}