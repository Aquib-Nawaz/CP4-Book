#include <iostream>
using namespace std;
int f(int k, int n){
    int  divider=1,res=0;
    while(n>=k*divider){
        int na=n/divider;
        res+=divider*((na+10-k)/10);
        if(n/divider%10==k)
            res-=divider-1-n%divider;
        divider*=10;
    }
    return res;
}

int f0(int n){
    int  divider=1,res=0;
    while(n>=10*divider){
        int na=n/divider;
        res+=divider*(na/10);
        if(n/divider%10==0)
            res-=divider-1-n%divider;
        divider*=10;
    }
    return res;
}
int main(){
    int T,d;
    scanf("%d", &T);
    while(T--){
        scanf("%d",&d);
        printf("%d",f0(d));
        for(int i=1;i<10;i++)printf(" %d",f(i,d));
        printf("\n");
    }
}