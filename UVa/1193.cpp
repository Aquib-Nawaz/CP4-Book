#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long double ld;
typedef long long ll;
#define EPS 1e-10

struct interval{
    ld l,r;
    bool operator <(const interval& _r) const{
        return l==_r.l?r>_r.r:l<_r.l;
    }
}arr[100000];

int n,d,C,ans;
ld d2,cx;

ld get_c(int x,int y, int m=1){
    return x+m*sqrt(d2-(ld)y*y);
}

int x,y;

int main(){
    C=0;
    while(scanf("%d %d",&n,&d),n||d){
        d2 = (ld)d*d;
        bool can=true;
        printf("Case %d: ",++C);
        for(int i=0;i<n;i++){
            scanf("%d%d",&x, &y);
            if(y>d)can=false;
            arr[i]={get_c(x,y,-1),get_c(x,y,1)};
        }
        if(!can){
            printf("-1\n");
            continue;
        }
        sort(arr,arr+n);
        ans=1,cx=arr[0].r;
        for(int i=1;i<n;i++){
            if(arr[i].l<=cx+EPS){
                cx = min(cx,arr[i].r);
            }
            else{
                ans++;
                cx = arr[i].r;
            }
        }
        printf("%d\n",ans);
    }
}