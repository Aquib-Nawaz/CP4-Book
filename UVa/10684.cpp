#include <iostream>
using namespace std;
int main(){
    int n,d,ret,v;
    while (scanf("%d",&n),n){
        ret = -1000,v=0;
        for(int i=0;i<n;i++){
            scanf("%d",&d);
            v+=d;
            if(v>ret)ret=v;
            if(v<0)v=0;
        }
        if(ret>0)
            printf("The maximum winning streak is %d.\n",ret);
        else
            printf("Losing streak.\n");
    }
}