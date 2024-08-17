#include <iostream>
using namespace std;

int main(){
    int d,N,P;
    scanf("%d%d",&N,&P);
    int ret=0;
    for(int val=0,i=0;i<N;i++){
        scanf("%d",&d);
        val+=d-P;
        if(ret<val)ret=val;
        if(val<0)val=0;
    }
    printf("%d",ret);

}