#include <iostream>
#include <cmath>
using namespace std;

void solve(int n){
    int a;
    for(int i=2*(sqrt(n));i>=1;i--){
        //(a+i-1)*i/2=n
        if(2*n%i==0&&(a=2*n/i-i+1)>0&&(a&1)==0){
            a>>=1;
            printf("%d = %d + ... + %d\n",n,a,a+i-1);
            return;
        }
    }
}

int main(){
    int d;
    while(scanf("%d",&d),d!=-1){
        solve(d);
    }
}