#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int s,d;
    while (scanf("%d %d",&s,&d)!=-1){
        int mb = ceil(5.0*d/(s+d))-1;
        int ns = 2*mb+min(mb,2),nd=12-ns;
        int df = ns*s-nd*d;
        if(df>0)printf("%d\n",df);
        else printf("Deficit\n");
    }
}