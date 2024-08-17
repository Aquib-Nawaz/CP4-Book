#include <iostream>
using namespace std;

int A[50000];

int main(){
    int N;
    scanf("%d",&N);
    for(int i=0;i<N;i++)scanf("%d",A+i);
    long long ans=0;
    for(int i=N-2;i>=0;i--){
        if(A[i]>A[i+1]-1){
            ans+=A[i]-A[i+1]+1,A[i]=A[i+1]-1;
            if(A[i]<0){printf("1"); return 0;}
        }
    }
    printf("%lld",ans);
}