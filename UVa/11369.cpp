#include <iostream>
#include <algorithm>
using namespace std;
int A[20000];
int main(){
    int T,N;
    scanf("%d",&T);
    while (T--){
        scanf("%d",&N);
        for(int i=0;i<N;i++)scanf("%d",A+i);
        sort(A,A+N,greater<int>());
        int ans=0;
        for(int i=2;i<N;i+=3)ans+=A[i];
        printf("%d\n",ans);
    }
}