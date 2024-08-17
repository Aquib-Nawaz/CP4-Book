#include <iostream>
#include <cstring>
using namespace std;
bool dp[10][360];

int arr[10],N;

bool solve(int n, int k){
    if(k==0)return true;
    if(n==N || dp[n][k]) return false;
    dp[n][k]=true;
    return solve(n+1,k)||solve(n,(k-arr[n]+360)%360)||solve(n,(k+arr[n])%360);
}

int main(){
    int k,d;
    scanf("%d %d",&N,&k);
    memset(dp,0,sizeof dp);
    for(int i=0;i<N;i++)scanf("%d",arr+i);
    for(int i=0;i<k;i++){
        scanf("%d",&d);
        printf("%s\n",solve(0,d)?"YES":"NO");
    }
}