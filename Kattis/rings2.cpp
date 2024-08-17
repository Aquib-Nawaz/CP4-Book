#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)

int A[102][102]={0};
char C[101];
int main(){
    int n,m, ring=0;
    scanf("%d %d\n", &n,&m);
    int mxring=0;
    REP(i,n){
        scanf("%s", C);
        REP(j,m){
            if(C[j]=='T')A[i+1][j+1]=-1;

        }
    }
    bool f=true;
    while(f){
        f=false, ring++;
        for(int i=1; i<=n;i++)for(int j=1; j<=m; j++){
                if(A[i][j]==-1 && (A[i][j+1]==ring-1 || A[i+1][j]==ring-1 || A[i][j-1]==ring-1||A[i-1][j]==ring-1)){
                    A[i][j]=ring;
                    f=true;
                }
            }
    }

    mxring = ring-1;
    int w = mxring>9?3:2,nst;
    REP(i,n){
        REP(j,m){
            nst = w-(A[i+1][j+1]==0?0:A[i+1][j+1]<10?1:A[i+1][j+1]<100?2:3);
            REP(k,nst)printf(".");
            if(A[i+1][j+1])printf("%d", A[i+1][j+1]);
        }
        printf("\n");
    }
}