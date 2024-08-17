#include <iostream>
#include <algorithm>
using namespace std;

int A[300];

int main(){
    int T,N;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=0;i<3*N;i++)scanf("%d", A+i);
        int S=0;
        sort(A,A+3*N);
        for(int l=0,r=3*N-1;l<r-1;l++,r-=2)S+=A[r-1];
        printf("%d\n",S);
    }
}