#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct mypair{
    int l,m;
    bool operator <(const mypair& _r) const{
        if(l!=_r.l)return l<_r.l;
        return m<_r.m;
    }
}arr[10000];

int dp[2][101];

int main(){
    int N,d,x;
    while(scanf("%d",&N),N){
        for(int i=0;i<N;i++)scanf("%d%d",&arr[i].l,&arr[i].m);
        sort(arr,arr+N);
        //
        memset(dp[0],0,sizeof dp[0]);
        for(int i=arr[0].m;i<=100;i++)dp[0][i] = 1;
        for(int i=1;i<N;i++){
            d = arr[i].m;
            x = i%2;
            for(int j=1;j<=100;j++){
                dp[x][j] = dp[1-x][j];
                //d>=j
                if(d==j)dp[x][j]++;
                dp[x][j] = max(dp[x][j],dp[x][j-1]);
            }
        }
        printf("%d\n",dp[x][100]);
    }
    printf("*\n");

}