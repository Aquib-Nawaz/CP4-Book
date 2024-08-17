#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define REP(i, n) for (int i = 0; i < (n); i++)

double dp[23][1100];
int K;
struct dish{
    int p;
    double f;
    bool operator <(const dish& rhs)const{
        return p<rhs.p;
    }
}arr[200];


int main() {
    int N,x,T, v,d;
    double t;
    while (scanf("%d%d%d%d",&N,&x,&T,&K), N || x || T || K) {
        v = (N+1)*x/1.1-(N+1)*T+1e-10;
        for(int i=0;i<K;i++){
            scanf("%d", &arr[2*i].p);
            t=0;
            for(int j=0;j<N+1;j++)scanf("%d",&d), t+=d;
            arr[2*i].f = t/(N+1);
            arr[2*i+1]=arr[2*i];
        }
        K*=2;
        sort(arr, arr+K);
        memset(dp,0,sizeof dp);
        for(int i=0;i<K;i++){
            for(int p=v-arr[i].p;p>=0;p--){
                for(int k=1;k<=2*(N+1);k++)
                    dp[k][p+arr[i].p] = max(dp[k][p+arr[i].p],dp[k-1][p]+arr[i].f);
            }
        }
        printf("%.2lf\n",dp[2*(N+1)][v]);
    }

    return 0;
}