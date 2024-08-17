#include <iostream>
#include <algorithm>

using namespace std;

int A[41], N,ts=0;
long long s=0;
void solve(int id){
    s-=ts;
    for(int i=id;i<N&&ts+A[i]<200;i++){
        ts+=A[i];
        solve(i+1);
        ts-=A[i];
    }
}

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++)scanf("%d",A+i),s+=A[i]*(1LL<<N-1);
    sort(A,A+N);
    solve(0);
    printf("%lld",s);
}