#include <iostream>
#include <cstdio>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))

using namespace std;
int main(){
    int a,b;
    while(scanf("%d %d", &a, &b),a!=0){
        if(min(a,b)==1)
            printf("%d",max(a,b));
        else if(min(a,b)==2){
            int t=max(a,b);
            printf("%d",4*(t/4)+2*min(2,t%4));
        }
        else{
            printf("%d",((a*b)+1)/2);
        }
        printf(" knights may be placed on a %d row %d column board.\n", a,b);
    }
}