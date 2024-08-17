#include <iostream>
#include <cstring>
using namespace std;

#define home "home"
#define guest "guest"
#define score "SCORE"
#define end "END"
#define start "START"
int units[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int getunits(int n){
    if(n<10)
        return units[n];
    else
        return units[n%10]+getunits(n/10);
}
int main(){

    char f[6],t[6];
    int h,m,s,pt,ct,g,nscanned;
    int scores[2],ans=0,id=0;
    while(scanf("%s %d:%d:%d",f,&h,&m,&s)!=EOF) {
        scores[0]=scores[1]=ans=0;
        id++;
        pt = h*3600+m*60+s;
        do{
            scanf("%s %d:%d:%d",f,&h,&m,&s);
            ct = h*3600+m*60+s;
            ans+=(ct-pt)*(getunits(scores[0])+getunits(scores[1]));
            if(strcmp(f,score)==0) {
                scanf("%s %d",t,&g);
                if(strcmp(t,home)==0) scores[0]+=g;
                else scores[1]+=g;
            }
            pt=ct;
        }
        while(strcmp(f,end)!=0);
        printf("Case %d: %d\n",id,ans);
    }
}