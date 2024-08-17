#include <iostream>
using namespace std;

void solve(int l, int r, int h,bool f=false){
    //N-x<1<<(h-1)
    if(r<l)return;
    int X = max(1,r-l+1-(1<<(h-1))+1);
    if(!f)printf(" ");
    printf("%d",l+X-1);
    solve(l,l+X-2,h-1);
    solve(l+X,r,h-1);
}

int main(){
    int N,H,C=0;
    while(scanf("%d%d",&N,&H),N){
        printf("Case %d: ",++C);
        if(1<<H<N+1){
            printf("Impossible.\n");
            continue;
        }
        solve(1,N,H, true);
        printf("\n");
    }

}