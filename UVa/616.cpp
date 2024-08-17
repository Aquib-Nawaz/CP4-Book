#include <iostream>
#include <cmath>
using namespace std;

int solve(int n){
    int ans=-1;
    int i;
    for(i=2;(n-1)>=pow(i,i-1)>=1;i++){
        bool err=false;
        long long _n=n;
        for(int j=0;j<i;j++){
            if(_n%i!=1){
                err=true;
                break;
            }
            _n = (_n-1)*(i-1)/i;
        }
        if(!err && _n%i==0) ans= i;
    }
    return ans;
}

int main(){
    int d;
    while (scanf("%d",&d),d>=0){
        int ans=solve(d);
        printf("%d coconuts, ",d);
        if(ans==-1)
            printf("no solution\n");
        else
            printf("%d people and 1 monkey\n",ans);
    }
}