#include <iostream>
#include <algorithm>
using namespace std;
struct inter{
    int x,t;
    bool operator<(const struct inter &a) const {
        return x > a.x;
    }
} arr[2][1000];
int main(){
    int N,n[2],K,x,t;
    scanf("%d %d",&N,&K);
    n[0]=n[1]=0;
    for(int i=0;i<N;i++){
        scanf("%d%d",&x,&t);
        arr[x>0][n[x>0]++]={abs(x),t};
    }

    long long ans=0;
    for(int j=0;j<2;j++) {
        sort(arr[j], arr[j] + n[j]);
        for (int cur = 0, next; cur<n[j]; cur = next) {
            ans += arr[j][cur].t / K * arr[j][cur].x*2;
            arr[j][cur].t %= K;
            if (arr[j][cur].t == 0){
                next=cur+1;
                continue;
            }
            int v = 0;
            for (next = cur; ; next++) {
                t = min(K - v, arr[j][next].t);
                v += t;
                arr[j][next].t -= t;
                if (v == K || next==n[j]-1){
                    ans += arr[j][cur].x*2;
//                    if(arr[j][next].t==0)next++;
                    break;
                }
            }
        }
    }
    printf("%lld\n",ans);
}