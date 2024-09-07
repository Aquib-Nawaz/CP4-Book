#include <iostream>
#include <cmath>
using namespace std;

typedef long double ld;
ld eq[2000];

int main(){
    int T,N;
    ld d;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &N);
        for(int i=0;i<N+1;i++)scanf("%Lf", eq+i);
        for(int i=0;i<N-2;i++){
            scanf("%Lf", &d);
            for(int j=1;j<N+1-i;j++)
                eq[j] += eq[j-1]*d;
        }
        ld a=eq[0],b=eq[1],c=eq[2];
        if(a<0)a=-a, b=-b,c=-c;
        ld D = sqrt(b*b-4*a*c);
        printf("%.1Lf\n%.1Lf\n", (-b+D)/(2*a), (-eq[1]-D)/(2*a));
    }
}