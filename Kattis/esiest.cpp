#include <iostream>
using namespace std;

int sum_digit(int n){
    int s=0;
    while (n){
        s+=n%10;
        n/=10;
    }
    return s;
}

int main(){
    int d,s,p;
    while(scanf("%d",&d),d){
        s=sum_digit(d);
        for(p=11;p<100;p++){
            if(sum_digit(p*d)==s)
                break;
        }
        printf("%d\n",p);
    }
}