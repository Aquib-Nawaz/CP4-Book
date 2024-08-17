#include <iostream>
using namespace std;

int r[3],c[3],C=0;
bool inRange(int a, int b, int d){
    return d>=min(a,b) && d<=max(a,b);
}

int main(){
    while(scanf("%d %d %d %d %d %d", &r[0], &c[0], &r[1], &c[1], &r[2], &c[2])!=EOF){
        printf("Case %d: ", ++C);
        int ans;
        if(abs(r[1]-r[0])!=abs(c[1]-c[0])){
            ans = max(abs(r[1]-r[0]), abs(c[1]-c[0]));
        }
        else {
            //y=mx+c
            int m = (c[1]-c[0])/(r[1]-r[0]);
            ans=abs(c[1]-c[0]);
            if(c[2]-m*r[2]==c[1]-m*r[1] && inRange(r[0], r[1], r[2]))ans++;
        }
        printf("%d\n", ans);
    }

}