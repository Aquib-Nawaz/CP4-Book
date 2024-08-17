#include <iostream>
#include <algorithm>
using namespace std;

#define EPS 1e-10

double A[100], B[200];

int main(){

    int N,M,K,d;
    scanf("%d %d %d",&N,&M,&K);

    for(int i=0;i<N;i++){scanf("%d",&d);A[i]=d;}
    for(int i=0;i<M;i++)scanf("%d",&d),B[i]=d;
    double rt2 = sqrt(2);
    for(int i=M;i<M+K;i++)scanf("%d",&d),B[i]=d/rt2;
    sort(A,A+N);
    sort(B,B+M+K);
    int ans=0;
    for(int i=0,j=0;i<N&&j<M+K;i++,j++){
        while(i<N&&A[i]<=B[j])i++;
        if(i==N)break;
        ans++;
    }
    printf("%d", ans);
}