#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define REP(i,j,n) for(int i=j;i<n;i++)
int A[1000001], f[1000001], B[1000001];
long long npow;
int main(){
    int t,n,a,b,c,x,y,j,base;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d %d %d %d", &n, &a, &b, &c, &x, &y);
        A[0]=a,npow=1;base=max(n,2);
        REP(i,1,n)A[i]=(int)(((long long)A[i-1]*b+a)%c);
        while(npow<max(a+1,c)){
            memset(f,0, sizeof f);
            REP(i,0,n)f[A[i]/npow%base]++;
            REP(i,1,base)f[i]+=f[i-1];
            for(int i=n-1;i>-1;i--){
                j=A[i]/npow%base;
                f[j]--;
                B[f[j]]=A[i];
            }
            memcpy(A, B, n*(sizeof (int)));
            npow*=base;
        }
        sort(A,A+n);
        long long ans=0;
        REP(i,0,n)ans = (ans*x+A[i])%y;
        printf("%lld", ans);
        if(t)printf("\n");
    }
}
