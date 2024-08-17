#include <iostream>
#include <algorithm>
using namespace std;
int A[500][500], N, M;

int ubnd(int l, int h, int x, int y, int v){
    int mid;
    while(h>l+1) {
        mid = l + (h - l) / 2;
        if(A[x+mid][y+mid]>v)h=mid-1;
        else l=mid;
    }
    if(h==l)return h;
    return l+(A[x+h][y+h]<=v);
}

int main(){
    int L,H,Q;
    while(scanf("%d %d", &N,&M),N!=0) {
        for(int i=0;i<N;i++)for(int j=0;j<M;j++)scanf("%d", &A[i][j]);
        scanf("%d",&Q);
        for(int i=0;i<Q;i++){
            int ans=-1;
            scanf("%d %d",&L,&H);

            for(int x=0;x<N;x++)
            {
                int y = lower_bound(A[x],A[x]+M,L) - A[x];
                if(y==M||A[x][y]>H)continue;

                ans = max(ans,ubnd(0,min(N-x,M-y)-1,x,y,H));
            }
            printf("%d\n",ans+1);
        }
        printf("-\n");
    }
}