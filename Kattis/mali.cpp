#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define REP(i,j,n) for(int i=j;i<n;i++)
int A[2][101], B[2][101];
int main(){
    int n,ans,i=0,a,b;
    scanf("%d", &n);
    while(i++<n) {
        scanf("%d %d", &a, &b);
        A[0][a]++;A[1][b]++;
        memcpy(B,A,sizeof A);
        a=1,b=100,ans=0;
        while(a<=100&&b>0){
            while(a<=100&&A[0][a]==0)a++;
            while(b>0&&A[1][b]==0)b--;
            if(b<=0||a>100)break;
            ans = max(ans, a+b);
            int m = min(A[0][a],A[1][b]);
            A[0][a]-=m;
            A[1][b]-=m;
        }
        memcpy(A,B,sizeof B);
        printf("%d", ans);
        if(i!=n)printf("\n");
    }
}
