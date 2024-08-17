#include <iostream>
using namespace std;
#define M 20
int S[1<<M];
struct{
    int a,b;
    bool t;
}Q[800];
int main(){

    int n,m, ans;
    bool err;
    while(scanf("%d %d",&n,&m),n){
        ans=0;
        for(int i=0;i<m;i++)scanf("%d %d",&Q[i].a,&Q[i].b), Q[i].a--,Q[i].t=Q[i].b>0, Q[i].b=abs(Q[i].b)-1;
        S[(1<<n)-1]=0;
        for(int i=(1<<n)-1,j=(1<<n)-2;i>0;i--){
            err=false;
            int u=S[i];
            for(int k=32-__builtin_clz(u);k<n;k++)S[j--]=u|(1<<k);
            u=~u&(1<<n)-1;
            for(int k=0;k<m;k++){
                if(!(u&1<<Q[k].a))continue;
                if((u&1<<Q[k].b)>0!=Q[k].t){
                    err=true;
                    break;
                }
            }
            if(!err){ans=__builtin_popcount(u);break;}
        }
        printf("%d\n",ans);
    }
}