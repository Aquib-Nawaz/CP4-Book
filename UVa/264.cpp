#include <iostream>
using namespace std;

int main(){
    int n;
    while (scanf("%d", &n)==1){
        int lo =1,hi=10000;
        while(hi-lo>1){
            int mid = (lo+hi)>>1;
            if(mid*(mid+1)/2<n)lo=mid+1;
            else hi=mid;
        }
        if(lo!=hi && lo*(lo+1)/2<n)lo++;
        int rem=n-lo*(lo-1)/2,r,c;
        if(lo&1)c=rem,r=lo+1-rem;
        else c=lo+1-rem,r=rem;
        printf("TERM %d IS %d/%d\n",n,r,c);
    }
}