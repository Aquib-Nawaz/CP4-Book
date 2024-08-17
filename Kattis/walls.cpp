#include <iostream>
#include <queue>
using namespace std;

struct P{
    double x,y;
}B[4];

int E[30],ans=5,n;

double dist(P a,P b){
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int getE(P p, int r){
    int ret=0;
    for(int i=0;i<4;i++){
        if(dist(p,B[i])-r*r<1e-10)ret|=1<<i;
    }
    return ret;
}

void solve(int idx, int l, int m){
    if(m==(1<<4)-1){
        ans=l;
        return;
    }
    if(l+1>=ans)return;
    for(int i=idx;i<n;i++){
        solve(i+1,l+1,m|E[i]);
    }
}

int main() {
    int l, w,  r,x,y;
    struct P p;
    scanf("%d %d %d %d", &l, &w, &n, &r);
    B[0] = {-l / 2.0, 0};
    B[1] = {l / 2.0, 0};
    B[2] = {0, w / 2.0};
    B[3] = {0, -w / 2.0};
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &x, &y);
        p = {(double )x, (double )y};
        E[i] = getE(p, r);
    }
    solve(0,0,0);
    if (ans<5)printf("%d",ans);
    else printf("Impossible");
}