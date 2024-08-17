#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int i;
    for( i=16; ;i++){
        bool err=false;
        for(int j=0;j<7;j++){
            long long x = ((long long)(i+j))*(i+j);
            int s=0;
            while(x>0)s+=x%10,x/=10;
            double rt = sqrt(s);
            int irt = rt;
            if(abs(irt-rt)>1e-10){err=true;i+=j;break;}
        }
        if(!err)break;
    }
    for(int j=0;j<7;j++){
        printf("%d %lld\n", i+j,((long long)(i+j))*(i+j));
    }
}