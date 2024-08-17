#include <iostream>
#include <algorithm>
using namespace std;

struct interval{
    int l,r;
    bool operator < (const interval& rhs) const{
        return l<rhs.l;
    }
}arr[10000];

int main(){
    int L,G,x,r;
    while(scanf("%d %d",&L,&G),L||G){
        for(int i=0;i<G;i++){
            scanf("%d %d",&x,&r);
            arr[i]={x-r,x+r};
        }
        sort(arr,arr+G);
        int ans=0,cur=0;
        int i=0,mx;
        while(i<G&&cur<L&&arr[i].l<=cur){
            mx=cur;
            for(;i<G&&arr[i].l<=cur;i++)mx=max(arr[i].r,mx);
            cur=mx;
            ans++;
        }
        if(cur<L)printf("-1\n");
        else printf("%d\n",G-ans);
    }

}