#include <iostream>
using namespace std;
int cost[4]={2,3,5,7};
int mp[4] = {100,9900,990000,2000000000};
int getW(int a){
    int ret=0,c;
    for(int i=0;i<4;i++){
        c = min(mp[i],a/cost[i]);
        ret += c;
        a -= c*cost[i];
    }
    return ret;
}

int getC(int w){
    int ret=0,c;

    for(int i=0;i<4;i++){
        c = min(mp[i],w);
        ret += c*cost[i];
        w -= c;
    }
    return ret;
}

int f(int x, int y, int d){
    return getC(x)-getC(y)+d;
}

int main(){
    int A,B,lo,hi,mid,t;
    while (scanf("%d %d",&A,&B),A) {
        lo=0,hi=getW(A);
        A=hi;
        while(hi>=lo){
            mid=(lo+hi)>>1,t=f(mid,A-mid,B);
            if(t==0)break;
            if(t<0)lo=mid+1;
            else hi=mid-1;
        }
        if(t!=0)return 1;
        printf("%d\n",getC(mid));
    }
}