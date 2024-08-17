#include <iostream>
#include <algorithm>
using namespace std;

double A[1001];
int C[1001];

int main(){
    int T;
    scanf("%d",&T);
    while (T--){
        int n,a,b;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a), scanf("%d",&b), A[i]=a*1.0/b;
        for(int i=0;i<n;i++)C[i]=i+1;
        stable_sort(C,C+n,[&](int a, int b){return A[a]<A[b];});
        for(int i=0;i<n;i++){
            if(i!=0)printf(" ");
            printf("%d",C[i]);
        }
        printf("\n");
        if(T!=0)
        printf("\n");
    }
}