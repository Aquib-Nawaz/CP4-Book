#include <iostream>
#include <cstring>
using namespace std;
bool dp[1000][2000];

int arr[1000],N;

bool solve(int n, int k){
    if(k==0)return true;
    if(n==N || k<0 || dp[n][k]) return false;
    dp[n][k]=true;
    return solve(n+1,k)||solve(n+1,k-arr[n]);
}

int main(){
    scanf("%d",&N);
    memset(dp,0,sizeof dp);
    for(int i=0;i<N;i++)scanf("%d",arr+i);
    for(int i=0;i<1000;i++)
        if(solve(0,1000+i)){
            printf("%d\n",1000+i);
            break;
        }
        else if(solve(0,1000-i)){
            printf("%d\n",1000-i);
            break;
        }
}