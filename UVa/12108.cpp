#include <iostream>
using namespace std;

#define REP(i,n) for(int i=0;i<(n);++i)
#define MAXN 9*8*7*5
int A[10][3];
int main(){
    int n,C=0,temp;
    while(scanf("%d", &n), n!=0){
        int awake=0,_=1;
    REP(i,n){REP(j,3)scanf("%d", A[i]+j);awake+=A[i][2]<=A[i][0];}

    while(_<=MAXN && awake!=n){
        temp=awake;
        REP(i,n)
        if(A[i][2]==A[i][0] && temp>=n-temp)A[i][2]=1;
        else if(A[i][2]==A[i][0])awake--,A[i][2]++;
        else if(A[i][2]==A[i][0]+A[i][1])awake++,A[i][2]=1;
        else A[i][2]++;
        _++;
    }
    printf("Case %d: %d\n", ++C,_>MAXN?-1:_);}
}