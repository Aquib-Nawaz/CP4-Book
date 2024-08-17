#include <iostream>
#include <algorithm>
using namespace std;

typedef long double ld;
ld arr[1000], arr1[1000], dp[1000],W;
int N;
#define EPS 1e-10
ld solve(int id){
    if(id==N)return 0;
    ld &ret=dp[id];
    if(ret!=-1)return ret;
    ld mx=0,w=0;
    ret=1e9;
    for(int i=id;i<N;i++){
        w += arr1[i];
        mx = max(arr[i],mx);
        if(w>W+EPS)break;
        ret = min(ret, mx+solve(i+1));
    }
    return ret;
}

int main(){
    while(scanf("%d%Lf", &N,&W),N){
        for(int i=0;i<N;i++)scanf("%Lf%Lf", &arr[i], &arr1[i]), dp[i]=-1;
        printf("%.4Lf\n", solve(0));
    }
}