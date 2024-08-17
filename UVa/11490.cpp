#include <iostream>
#include <cmath>
using namespace std;

void solve(long long d){
    bool f=false;
    long long b;
    d*=24;
    //(2x+3y)*(x+2y)=d+2x^2=>6y^2+7xy-d=0
    //y=(-b+D)/12 where D^2=(7x)^2+24d
    //6*(i/12)^2+(i/12)*(24d/i-i)/2-d=0
    for(long long i=12;i*i<=d;i+=12)
        if(d%i==0&&(b=d/i-i)%14==0){
            b>>=1;
            if(b>0){
               b/=7;
               b%=100000007;
               printf("Possible Missing Soldiers = %lld\n",2*b*b%100000007);
               f= true;
            }
        }
    if(!f)printf("No Solution Possible\n");
    printf("\n");
}

int main(){
    long long d;
    while(scanf("%lld",&d),d!=0)solve(d);
}