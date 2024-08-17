#include <iostream>
#include <algorithm>
using namespace std;

#define REP(i,n) for(int i=0;i<n; i++)
int A[10000];
int main(){
    int N,M;
    while(scanf("%d %d", &N,&M), N||M) {
        REP(i, N)scanf("%d", &A[i]);
        sort(A, A + N, [&M](int a, int b) {
            if ((a % M + M) == (b % M + M)) {
                if ((a & 1) != (b & 1))return (a & 1) == 1;
                else if (a & 1)
                    return a > b;
                else return a < b;
            }
            return a % M < b % M;
        });
        printf("%d %d\n", N, M);
        REP(i, N)printf("%d\n", A[i]);
    }
    printf("0 0\n");
    return 0;
}