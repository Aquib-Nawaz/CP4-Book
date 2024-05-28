#include <iostream>

using namespace std;

bool inbetween(int a,int b, int c){
    return (a<=b && b<=c) ;
}
int main(){
    int n,wh1,wm1,wh2,wm2,mh1,mm1,mh2,mm2;
    scanf("%d",&n);
    int i=1;
    while(i<=n){
        scanf("%d:%d %d:%d",&wh1,&wm1,&wh2,&wm2);
        scanf("%d:%d %d:%d",&mh1,&mm1,&mh2,&mm2);
        int ws = wh1*60+wm1, we=wh2*60+wm2;
        int ms = mh1*60+mm1, me=mh2*60+mm2;
        if(inbetween(ws,ms,we)||inbetween(ws,me, we)||inbetween(ms,ws,me))
            printf("Case %d: Mrs Meeting\n", i);
        else
            printf("Case %d: Hits Meeting\n", i);
        i++;
    }
}