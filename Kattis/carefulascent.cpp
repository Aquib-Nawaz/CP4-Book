#include <iostream>
using namespace std;

int main(){
    int x,y,n,l,u;
    double f,d=0;
    scanf("%d %d %d",&x,&y,&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %lf",&l,&u,&f);
        y-=(u-l);
        d+=(u-l)*f;
    }
    d+=y;
    printf("%.6lf",x/d);
}