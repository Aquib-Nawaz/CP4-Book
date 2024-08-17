#include <iostream>
#include <cstring>
using namespace std;
int A[61];
int dp[181], dp1[181];
int main(){
    memset(A,0, sizeof A);
    memset(dp,0, sizeof dp);
    memset(dp1,0, sizeof dp1);
    A[0]=A[50]=1;
    for(int i=1;i<=20;i++)A[i]=A[2*i]=A[3*i]=1;
    int j=0;
    for(int i=0; i<=60;i++)if(A[i])A[j++]=i;
    for(int i=0;i<j;i++)for(int k=0;k<j;k++)for(int l=0;l<j;l++)dp[A[i]+A[l]+A[k]]++;
    for(int i=0;i<j;i++)for(int k=i;k<j;k++)for(int l=k;l<j;l++)dp1[A[i]+A[l]+A[k]]++;
    int n;
    while(scanf("%d", &n), n>0){
        if(n>180||dp[n]==0)printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n",n);
        else{
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n,dp1[n]);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n,dp[n]);
        }
        printf("**********************************************************************\n");
    }
    printf("END OF OUTPUT\n");
    return 0;
}