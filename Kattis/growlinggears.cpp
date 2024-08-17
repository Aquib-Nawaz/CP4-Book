#include <iostream>
using namespace std;

double getTorque(){
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    return (b*b+4.0*a*c)/4*a;
}

int main(){
    int T,n;
    double t;
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        int id=1;
        double ans=getTorque();
        for(int i=2;i<=n;i++)
            if((t=getTorque())>ans)id=i,ans=t;
        printf("%d\n",id);
    }
}