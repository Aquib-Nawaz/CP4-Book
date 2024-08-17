#include <iostream>
using namespace std;

int main(){
    int T,l,n,d;
    scanf("%d",&T);
    while(T--){
        int mn=0,mx=0;
        scanf("%d%d",&l,&n);
        for(int i=0;i<n;i++)scanf("%d",&d), mn=max(mn,min(d,l-d)), mx=max(mx,max(d,l-d));
        printf("%d %d\n",mn,mx);
    }
}