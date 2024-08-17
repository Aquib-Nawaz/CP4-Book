#include <iostream>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
int A[4];
long long S,P;
void print(double a, double b, double c, double d){
    printf("%.2lf %.2lf %.2lf %.2lf\n",a/100,b/100,c/100,d/100);
}
int main(){
    for(A[0]=1;4*A[0]<=2000;A[0]++)for(A[1]=A[0];A[0]+3*A[1]<=2000;A[1]++)
        for(A[2]=A[1];A[0]+A[1]+2*A[2]<=2000;A[2]++){
            S =0,P=1; REP(i,3)S+=A[i],P*=A[i];
            if(P>1000000&&(S*1000000)%(P-1000000)==0){
                A[3]=(S*1000000)/(P-1000000);
                if(A[3]>=A[2]&&A[3]+S<=2000)print(A[0],A[1],A[2],A[3]);
            }
        }
    return 0;
}