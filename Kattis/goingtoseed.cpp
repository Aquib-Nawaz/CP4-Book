#include <iostream>
using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    int m1,m2,m3,lo=1,hi=N,u,v;
    for(int i=0;hi-lo>=3;i++){
        double middle = (hi - lo + 1) / 2.0;

        m2 = lo + (int) (middle - 1);
        m1 = lo + (int) (middle / 2);
        m3 = m1 + (int) (middle - 1);
        printf("Q %d %d %d %d\n",lo,m2,m1,m3);
        fflush(stdout);
        scanf("%d %d",&u,&v);

        if(u&&v){
            lo=m1;
            hi=m2;
        }
        else if(u==1){
            hi=m1-1;
        }
        else if(v==1){
            lo=m2+1;
            hi=m3;
        }
        else{
            lo=m3+1;
        }
        if(lo==hi)
        {printf("A %d\n",lo); return 0;}
        lo = max(1,lo-1),hi=min(N,hi+1);
    }
    printf("Q %d %d %d %d\n",lo,lo,lo+1,lo+1);
    fflush(stdout);
    scanf("%d %d",&u,&v);
    int ans;
    if(u==1)ans=lo;
    else if(v==1)ans=lo+1;
    else ans=hi;
    printf("A %d\n",ans);

}