#include <iostream>
using namespace std;

int main(){
    int n;
    while (scanf("%d",&n),n){
        double ret=-1,val=0,p;
        int prev = -1,st,stp,x,cst=0;
        for (int i=0;i<n;i++){
            scanf("%d%lf",&x,&p);

            if(prev==-1 || val-0.08*(x-prev-1)<1e-10)val=0,prev=-1;

            val+= p - (prev==-1?1: (x-prev))*.08;
            if(val>ret+1e-10 || val>ret+1e-10 && stp-st>x-cst) ret = val, st=(prev==-1?x:cst),stp=x;
            if(prev==-1)cst=x;

            prev=x;
        }
        if(ret<1e-10)printf("no profit\n");
        else  printf("%.2lf %d %d\n",ret,st,stp);
    }
}