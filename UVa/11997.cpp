#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct Val{
    int i,j,v;
    Val(int _i, int _j, int _v):i(_i),j(_j),v(_v){}
    bool operator<(const Val& rhs) const {
        return v > rhs.v;
    }
};

#define REP(i,n) for (int i=0;i<n;i++)
int A[750][750], pqp[750], temp[750];
int main(){
    int k;
    while(scanf("%d", &k)!=-1){
        REP(i,k){REP(j,k)scanf("%d",&A[i][j]); sort(A[i], A[i]+k);}
        REP(j,k)pqp[j]=A[0][j];
        REP(i,k-1){
            priority_queue<Val>pqc;
            REP(j,k)pqc.emplace(j,0,A[i+1][j]+pqp[0]);
            REP(j,k){Val v = pqc.top(); temp[j]=v.v; pqc.pop(); pqc.emplace(v.i,v.j+1, A[i+1][v.i]+pqp[v.j+1]);}
            REP(j,k)pqp[j]=temp[j];
        }
        REP(i,k){if(i!=0)printf(" "); printf("%d", pqp[i]); }
        printf("\n");
    }

}