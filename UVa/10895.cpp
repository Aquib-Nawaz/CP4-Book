#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int A[1001][1001],B[1001];
int main(){
    int n,m, k, d;
    while(scanf("%d %d",&n,&m)!=EOF) {
        memset(A,0,sizeof A);
        for (int i = 0; i < n; i++) {
            scanf("%d", &k);
            for (int j = 0; j < k; j++) {
                scanf("%d", &B[j]);
            }
            for (int j = 0; j < k; j++) {
                scanf("%d", &d);
                A[i][B[j]-1] = d;
            }
        }
        printf("%d %d\n", m, n);
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (A[i][j])cnt++;
            }
            printf("%d", cnt);

            for (int i = 0; i < n; i++) {
                if (A[i][j]) {
                    printf(" %d", i + 1);
                }
            }
            printf("\n");
            bool f = 1;
            for (int i = 0; i < n; i++) {
                if (A[i][j]) {
                    if (!f)printf(" ");
                    printf("%d", A[i][j]);
                    f = 0;
                }
            }
            printf("\n");
        }
    }
}