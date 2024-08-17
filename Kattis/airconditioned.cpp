#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define EPS 1e-10

struct interval{
    int l,r;
    bool operator <(const interval& _r) const{
        return l==_r.l?r>_r.r:l<_r.l;
    }
}arr[100];

int n,d,ans,cx;


int x,y;

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&x, &y);
        arr[i]={x,y};
    }

    sort(arr,arr+n);
    ans=1,cx=arr[0].r;
    for(int i=1;i<n;i++){
        if(arr[i].l<=cx){
            cx = min(cx,arr[i].r);
        }
        else{
            ans++;
            cx = arr[i].r;
        }
    }
    printf("%d\n",ans);

}