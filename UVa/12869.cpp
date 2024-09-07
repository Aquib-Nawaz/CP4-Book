#include <iostream>
int main(){
    unsigned long long a,b;
    while(scanf("%llu %llu",&a,&b),a||b){
        a=a/5;
        b=b/5;
        printf("%llu\n",b-a+1);
    }
}