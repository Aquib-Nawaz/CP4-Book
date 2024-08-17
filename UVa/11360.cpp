#include <iostream>
#include <cstring>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int A[10][10];
char command[10];
int main(){
    int T,N, a, Q;
    scanf("%d", &T);
    REP(C,T){
        printf("Case #%d\n", C+1);
        scanf("%d",&N);
        REP(i,N){
            scanf("%d", &a);
            for(int j=N-1;j>=0; j--){
                A[i][j] = a%10;
                a /= 10;
            }
        }
        scanf("%d",&Q);
        REP(_,Q){
            scanf("%s", command);
            int l,r;
            if(strcmp(command, "row")==0){
                scanf("%d %d", &l, &r);
                REP(i,N)swap(A[l-1][i], A[r-1][i]);
            }
            else if(strcmp(command, "col")==0){
                scanf("%d %d", &l, &r);
                REP(i,N)swap(A[i][l-1], A[i][r-1]);
            }
            else if(strcmp(command, "inc")==0){
                REP(i,N)REP(j,N) A[i][j] = (A[i][j]+1)%10;
            }
            else if(strcmp(command, "dec")==0){
                REP(i,N)REP(j,N) A[i][j] = (A[i][j]+9)%10;
            }
            else if(strcmp(command, "transpose")==0){
                REP(i,N)REP(j,i) swap(A[i][j], A[j][i]);
            }
        }
        REP(i,N){
            REP(j,N)printf("%d", A[i][j]);
            printf("\n");
        }
        printf("\n");
    }
}