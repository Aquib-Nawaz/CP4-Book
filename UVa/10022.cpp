#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n,m,T,r1,c1,r2,c2;
    scanf("%d", &T);
    while (T--){
        scanf("%d %d", &n,&m);
        if(n>m)swap(n,m);
        r1 = ceil(sqrt(n));
        r2 = ceil(sqrt(m));
        c1 = n - (r1-1)*(r1-1);
        c2 = m - (r2-1)*(r2-1);
//        printf("%d %d %d %d\n", r1, c1, r2, c2);
        int rd = r2-r1, cd = abs(c2-c1-r2+r1);
        if(cd>=rd)
            printf("%d\n", rd+cd);
        else {
            int ans=2*cd;
            rd-=cd;
            if(rd%2)rd--,ans+=c1%2?1:3;
            ans+=2*rd;
            printf("%d\n", ans);
        }
        if(T)printf("\n");
    }
}