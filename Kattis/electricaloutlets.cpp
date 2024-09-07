#include <iostream>
using namespace std;

int main(){
    int T,N,d;
    scanf("%d", &T);
    while (T--){
        scanf("%d", &N);
        int ans = -N+1;
        for(int i=0;i<N;i++)scanf("%d", &d), ans+=d;
        printf("%d\n", ans);
    }
}